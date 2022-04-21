using System;
using System.Numerics;
using System.Threading.Tasks;
using Nethereum.Contracts;
using Nethereum.Hex.HexTypes;
using Nethereum.Web3;

namespace cryptomonBridge
{
   class Program
   {
        static void Main(string[] args)
        {
            //The URL endpoint for the blockchain network.
            string url = "HTTP://localhost:7545";                               //The contract address.
            string address = "0x1ADE4fa56c1175B4155a49368f3F550CEc3d2dCc";      //The ABI for the contract.
            string ABI = @"[{'inputs':[{'internalType':'uint32','name':'cID_','type':'uint32'},{'internalType':'uint32','name':'mID_','type':'uint32'}],'name':'addMove','outputs':[{'internalType':'string','name':'','type':'string'}],'stateMutability':'nonpayable','type':'function'},{'inputs':[{'internalType':'string','name':'n','type':'string'},{'internalType':'uint32','name':'a','type':'uint32'},{'internalType':'uint32','name':'d','type':'uint32'},{'internalType':'uint32','name':'h','type':'uint32'}],'name':'createCryptomon','outputs':[{'internalType':'string','name':'','type':'string'}],'stateMutability':'nonpayable','type':'function'},{'inputs':[{'internalType':'string','name':'n','type':'string'},{'internalType':'uint32','name':'d','type':'uint32'},{'internalType':'uint32','name':'m','type':'uint32'}],'name':'createMove','outputs':[{'internalType':'string','name':'','type':'string'}],'stateMutability':'nonpayable','type':'function'},{'inputs':[{'internalType':'uint32','name':'','type':'uint32'}],'name':'cryptomonList','outputs':[{'internalType':'uint32','name':'id','type':'uint32'},{'internalType':'string','name':'name','type':'string'},{'internalType':'uint32','name':'attack','type':'uint32'},{'internalType':'uint32','name':'defense','type':'uint32'},{'internalType':'uint32','name':'hp','type':'uint32'},{'internalType':'address','name':'owner','type':'address'},{'components':[{'internalType':'uint32','name':'id','type':'uint32'},{'internalType':'string','name':'name','type':'string'},{'internalType':'uint32','name':'damage','type':'uint32'},{'internalType':'uint32','name':'missRate','type':'uint32'}],'internalType':'struct creator.move','name':'move1','type':'tuple'},{'components':[{'internalType':'uint32','name':'id','type':'uint32'},{'internalType':'string','name':'name','type':'string'},{'internalType':'uint32','name':'damage','type':'uint32'},{'internalType':'uint32','name':'missRate','type':'uint32'}],'internalType':'struct creator.move','name':'move2','type':'tuple'}],'stateMutability':'view','type':'function'},{'inputs':[{'internalType':'address','name':'addr_','type':'address'}],'name':'getCryptomonByAddress','outputs':[{'internalType':'uint32','name':'','type':'uint32'}],'stateMutability':'view','type':'function'},{'inputs':[{'internalType':'uint32','name':'cID_','type':'uint32'}],'name':'getCryptomonByID','outputs':[{'internalType':'string','name':'','type':'string'}],'stateMutability':'view','type':'function'},{'inputs':[{'internalType':'uint32','name':'','type':'uint32'}],'name':'movesList','outputs':[{'internalType':'uint32','name':'id','type':'uint32'},{'internalType':'string','name':'name','type':'string'},{'internalType':'uint32','name':'damage','type':'uint32'},{'internalType':'uint32','name':'missRate','type':'uint32'}],'stateMutability':'view','type':'function'},{'inputs':[{'internalType':'uint32','name':'cID_','type':'uint32'},{'internalType':'address','name':'newOwner_','type':'address'}],'name':'updateOwner','outputs':[{'internalType':'string','name':'','type':'string'}],'stateMutability':'nonpayable','type':'function'}]";     
            HexBigInteger gas = new HexBigInteger(new BigInteger(400000));
            HexBigInteger value = new HexBigInteger(new BigInteger(0));


            // Creates the connection to the network and gets an instance of the contract.
            Web3 web3 = new Web3(url);
            Contract creator = web3.Eth.GetContract(ABI, address);
            // Console.WriteLine($"Creator: {creator.ToString()}");
            Task<string> artzimon = creator.GetFunction("createCryptomon").SendTransactionAsync(address, gas, value, "Artzimon", 0, 0, 200);
            artzimon.Wait();
            Console.WriteLine($"{artzimon.Result.ToString()}");

            // Task<string> artzimonID = creator.GetFunction("getCryptomonByAddress").SendTransactionAsync(address, gas, value, ((int)(char*)artzimon.Result).ToString());
            // artzimonID.Wait();
            // Console.WriteLine($"ID: {artzimonID.Result.ToString()}");

            Task<string> artzimonToString = creator.GetFunction("getCryptomonByID").SendTransactionAsync(address, gas, value, 0);
            artzimonToString.Wait();
            Console.WriteLine($"ID: {artzimonToString.Result}!");

            // get the cryptomon list
            Task<int> cryptomonList = creator.GetFunction("cryptomonList").CallAsync<int>(); // should get all information associated with the variable (public function)
            cryptomonList.Wait();
            var cryptomonList_ = (int)cryptomonList.Result; // store the variable information

            Console.WriteLine("Cryptomon List: " + cryptomonList_.ToString()); // write the information from cryptomon list

            // Contract voteContract = web3.Eth.GetContract(ABI, address);     //Reads the vote count for Candidate 1 and Candidate 2
            // Task<BigInteger> candidate1Function = voteContract.GetFunction("candidate1").CallAsync<BigInteger>();
            // candidate1Function.Wait();
            // int candidate1 = (int)candidate1Function.Result;

            // Task<BigInteger> candidate2Function = voteContract.GetFunction("candidate2").CallAsync<BigInteger>();
            // candidate2Function.Wait();
            // int candidate2 = (int)candidate2Function.Result;

            // Console.WriteLine("Candidate 1 votes: {0}", candidate1);
            // Console.WriteLine("Candidate 2 votes: {0}", candidate2);     //Prompts for the account address.
            // Console.Write("Enter the address of your account: ");

            // string accountAddress = Console.ReadLine();     //Prompts for the users vote.
            // int vote = 0;
            // Console.Write("Press 1 to vote for candidate 1, Press 2 to vote for candidate 2: ");
            // Int32.TryParse(Convert.ToChar(Console.Read()).ToString(), out vote);
            // Console.WriteLine("You pressed {0}", vote);    //Executes the vote on the contract.

            // try
            // {
            //     HexBigInteger gas = new HexBigInteger(new BigInteger(400000));
            //     HexBigInteger value = new HexBigInteger(new BigInteger(0));
            //     Task<string> castVoteFunction = voteContract.GetFunction("castVote").SendTransactionAsync(accountAddress, gas, value, vote);
            //     castVoteFunction.Wait();
            //     Console.WriteLine("Vote Cast!");
            // }

            // catch (Exception e)
            // {
            //     Console.WriteLine("Error: {0}", e.Message);
            // }
        }
    }
}
