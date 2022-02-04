pragma solidity >=0.4.21 <0.6.0;
pragma experimental ABIEncoderV2;

contract supplyChain {
    uint32 public product_id = 0;   // Product ID
    uint32 public participant_id = 0;   // Participant ID
    uint32 public owner_id = 0;   // Ownership ID
    uint32 public truck_id = 0;
    string[] public locations;
    uint32 public store_id = 0;
    string[] public tempInventory;
    uint32 public order_id = 0;


    struct product {
        string modelNumber;
        string partNumber;
        string serialNumber;
        address productOwner;
        uint32 cost;
        uint32 mfgTimeStamp;
    }
    mapping(uint32 => product) public products;

    struct participant {
        string userName;
        string password;
        string participantType;
        address participantAddress;
    }
    mapping(uint32 => participant) public participants;

    struct truck {
        uint id;
        uint quantity;
        product p;
        uint arrivalTime;
        string location;
        address driver;
    }
    mapping(uint32 => truck) trucks;
    
    struct retailer {
        address storeName;
        uint id;
        string location;
        product[] inventory;
        uint revenue;
    }
    mapping(uint32 => retailer) stores;

    struct order {
        retailer r;
        product p;
        uint quantity;
        uint orderNumber;
    }
    mapping(uint32 => order) orders;

    struct ownership {
        uint32 productId;
        uint32 ownerId;
        uint32 trxTimeStamp;
        address productOwner;
    }
    mapping(uint32 => ownership) public ownerships; // ownerships by ownership ID (owner_id)
    mapping(uint32 => uint32[]) public productTrack;  // ownerships by Product ID (product_id) / Movement track for a product

    event TransferOwnership(uint32 productId);

    function newStore(string memory l) public returns (string memory) {
        uint32 ID = store_id++;
        stores[ID].id = ID;
        stores[ID].storeName = msg.sender;
        stores[ID].location = l;
        return ("New store Created");
    }

    function addStock(uint32 storeID, uint quantity, string memory modelNumber_, string memory partNumber_, string memory serialNumber_, uint32 cost_, uint32 stamp_) public {
        product memory p = product(modelNumber_, partNumber_, serialNumber_, stores[storeID].storeName, cost_, stamp_ );
        stores[storeID].inventory.push(p);
    }

    function getStock(uint32 storeID) public {
        delete tempInventory;
        if (stores[storeID].id == storeID) {
            for (uint i = 0; i < stores[storeID].inventory.length; i++) {
                tempInventory.push(stores[storeID].inventory[i].serialNumber);
            }
        } else { tempInventory.push("No Items"); }
    }

    function printStock(uint32 id) public view returns (string[] memory tempInventory) {}

    function newShipment(uint q, uint32 productID, uint time, string memory l) public returns (string memory) {
        uint32 truckID = truck_id++;
        trucks[truckID].id = truckID;
        trucks[truckID].quantity = q;
        trucks[truckID].p = products[productID];
        trucks[truckID].driver = msg.sender;
        trucks[truckID].arrivalTime = time;
        trucks[truckID].location = l;
        return ("New Shipment Created");
    }

    function addLocation(string memory name) public {
        locations.push(name);
    }

    function ship(uint32 truckID, string memory location) public view returns (bool) {
        if (trucks[truckID].id == truckID) {
            for (uint i = 0; i < locations.length; i++) {
                if (keccak256(abi.encodePacked(locations[i])) == keccak256(abi.encodePacked(location))) {
                    return true;
                }
            }
        }
        return (false);
    }

    function addParticipant(string memory _name, string memory _pass, address _pAdd, string memory _pType) public returns (uint32){
        uint32 userId = participant_id++;
        participants[userId].userName = _name;
        participants[userId].password = _pass;
        participants[userId].participantAddress = _pAdd;
        participants[userId].participantType = _pType;
        return userId;
    }

    function getParticipant(uint32 _participant_id) public view returns (string memory, address ,string memory) {
        return (participants[_participant_id].userName, participants[_participant_id].participantAddress, participants[_participant_id].participantType);
    }

    function addProduct(uint32 _ownerId, string memory _modelNumber, string memory _partNumber, string memory _serialNumber, uint32 _productCost) public returns (uint32) {
        if(keccak256(abi.encodePacked(participants[_ownerId].participantType)) == keccak256("Manufacturer")) {
            uint32 productId = product_id++;
            products[productId].modelNumber = _modelNumber;
            products[productId].partNumber = _partNumber;
            products[productId].serialNumber = _serialNumber;
            products[productId].cost = _productCost;
            products[productId].productOwner = participants[_ownerId].participantAddress;
            products[productId].mfgTimeStamp = uint32(now);
            return productId;
        }
        return 0;
    }

    modifier onlyOwner(uint32 _productId) {
        require(msg.sender == products[_productId].productOwner,"");
        _;
    }

    function getProduct(uint32 _productId) public view returns (string memory,string memory,string memory,uint32,address,uint32){
        return (products[_productId].modelNumber, products[_productId].partNumber, products[_productId].serialNumber,
                products[_productId].cost, products[_productId].productOwner, products[_productId].mfgTimeStamp);
    }

    function newOwner(uint32 _user1Id,uint32 _user2Id, uint32 _prodId) onlyOwner(_prodId) public returns (bool) {
        participant memory p1 = participants[_user1Id];
        participant memory p2 = participants[_user2Id];
        uint32 ownership_id = owner_id++;
        if(keccak256(abi.encodePacked(p1.participantType)) == keccak256("Manufacturer")
            && keccak256(abi.encodePacked(p2.participantType))==keccak256("Supplier")){
            ownerships[ownership_id].productId = _prodId;
            ownerships[ownership_id].productOwner = p2.participantAddress;
            ownerships[ownership_id].ownerId = _user2Id;
            ownerships[ownership_id].trxTimeStamp = uint32(now);
            products[_prodId].productOwner = p2.participantAddress;
            productTrack[_prodId].push(ownership_id);
            emit TransferOwnership(_prodId);
            return (true);
        }
        else if(keccak256(abi.encodePacked(p1.participantType)) == keccak256("Supplier") && keccak256(abi.encodePacked(p2.participantType))==keccak256("Supplier")){
            ownerships[ownership_id].productId = _prodId;
            ownerships[ownership_id].productOwner = p2.participantAddress;
            ownerships[ownership_id].ownerId = _user2Id;
            ownerships[ownership_id].trxTimeStamp = uint32(now);
            products[_prodId].productOwner = p2.participantAddress;
            productTrack[_prodId].push(ownership_id);
            emit TransferOwnership(_prodId);
            return (true);
        }
        else if(keccak256(abi.encodePacked(p1.participantType)) == keccak256("Supplier") && keccak256(abi.encodePacked(p2.participantType))==keccak256("Consumer")){
            ownerships[ownership_id].productId = _prodId;
            ownerships[ownership_id].productOwner = p2.participantAddress;
            ownerships[ownership_id].ownerId = _user2Id;
            ownerships[ownership_id].trxTimeStamp = uint32(now);
            products[_prodId].productOwner = p2.participantAddress;
            productTrack[_prodId].push(ownership_id);
            emit TransferOwnership(_prodId);
            return (true);
        }
        return (false);
    }

    function getProvenance(uint32 _prodId) external view returns (uint32[] memory) { return productTrack[_prodId]; }

    function getOwnership(uint32 _regId)  public view returns (uint32,uint32,address,uint32) {
        ownership memory r = ownerships[_regId];
        return (r.productId,r.ownerId,r.productOwner,r.trxTimeStamp);
    }

    function authenticateParticipant(uint32 _uid, string memory _uname, string memory _pass, string memory _utype) public view returns (bool) {
        if(keccak256(abi.encodePacked(participants[_uid].participantType)) == keccak256(abi.encodePacked(_utype))) {
            if(keccak256(abi.encodePacked(participants[_uid].userName)) == keccak256(abi.encodePacked(_uname))) {
                if(keccak256(abi.encodePacked(participants[_uid].password)) == keccak256(abi.encodePacked(_pass))) {
                    return (true);
                }
            }
        }
        return (false);
    }
}