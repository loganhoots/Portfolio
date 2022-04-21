//const cryptomon = artifacts.require("./cryptomon.sol");
const creator = artifacts.require("./creator.sol");

/*
 * uncomment accounts to access the test accounts made available by the
 * Ethereum client
 * See docs: https://www.trufflesuite.com/docs/truffle/testing/writing-tests-in-javascript
 */

contract('cryptomon', async accounts => {
  /*

  it("should assert true", async () => {
    let instance = await creator.deployed();
    let cryptomonID = await instance.createCryptomon("Citromon", 10, 10, 10);
    let c = await instance.cryptomonList(0);

    assert.equal(c[1], "Citromon");
  });

  it("should assert true", async () => {
    let instance = await creator.deployed();
    let moveID = await instance.createMove("The Lick", 10);
    let m = await instance.movesList(0);
    assert.equal(m[1], "The Lick");
  });

  it("should assert true", async () => {
    let instance = await creator.deployed();
    let cryptomonID = await instance.createCryptomon("Citromon", 10, 10, 10);
    let moveID = await instance.createMove("The Lick", 10);
    let temp = await instance.addMove(0, 0);
    let c = await instance.cryptomonList(0);

    assert.equal(c[6][1], "The Lick");
  });

  it("should assert true", async () => {
    let instance = await creator.deployed();

    // let cryptomonID = await instance.createCryptomon("Citromon", 10, 10, 10);
    // let moveID = await instance.createMove("The Lick", 10);
    // moveID = await instance.createMove("Suckle", 69);
    // let temp = await instance.addMove(0, 0);
    // temp = await instance.addMove(0, 1);

    // let c = await instance.cryptomonList(0);

    let i = await instance.cryptomonList(1);
    let cryptomonID = await instance.createCryptomon("Artzimon", 10, 10, 10);
    let moveID = await instance.createMove("Popping Germans", 10);
    moveID = await instance.createMove("Debug", 69);
    let temp = await instance.addMove(1, 2);
    temp = await instance.addMove(1, 3);


    assert.equal(i[1], "Artzimon");
    // assert.equal(c[1], "Citromon");
  })
  
  */

  // test creating two cryptomons
  it("should assert true", async () => {
    // deploy creator contract
    let instance = await creator.deployed();

    // create first cryptomon with multiple moves
    let cryptomonID = await instance.createCryptomon("Citromon", 10, 10, 10);
    let moveID = await instance.createMove("The Lick", 10, 80);
    moveID = await instance.createMove("Suckle", 69, 30);
    let temp = await instance.addMove(0, 0);
    temp = await instance.addMove(0, 1);

    // create second cryptomon with multiple moves
    let cryptomonID2 = await instance.createCryptomon("Citromon2", 10, 10, 10);
    let moveID2 = await instance.createMove("The Lick2", 10, 80);
    moveID2 = await instance.createMove("Suckle2", 69, 30);
    let temp2 = await instance.addMove(1, 2);
    temp2 = await instance.addMove(1, 3);

    // get cryptomon from list
    let c = await instance.cryptomonList(0);
    let c2 = await instance.cryptomonList(1);

    // get moves from list
    let m = await instance.movesList(0);
    let m2 = await instance.movesList(1);
    
    // console.log(m2);

    // assert the cryptomon names
    assert.equal(c[1], "Citromon");
    assert.equal(c2[1], "Citromon2");

    // assert that the first cryptomon has the correct moves
    assert.equal(c[6][1], "The Lick");
    assert.equal(c[7][1], "Suckle");

    // assert that the second cryptomon has the correct moves
    assert.equal(c2[6][1], "The Lick2");
    assert.equal(c2[7][1], "Suckle2");
  });

  // it("should assert true", async () => {
  //   let instance = await creator.deployed();

  //   let cryptomonID = await instance.createCryptomon("Citromon", 10, 10, 10);
  //   let cryptomonID2 = await instance.createCryptomon("Citromon2", 10, 10, 10);

  //   let c = await instance.cryptomonList(0);
  //   let c2 = await instance.cryptomonList(1);

  //   let change = await instance.updateOwner(0, c2.owner);

  //   assert.equal(c.owner, c2.owner);
  // })
});
