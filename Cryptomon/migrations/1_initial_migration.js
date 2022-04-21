const creator = artifacts.require("./creator.sol");

module.exports = async function (deployer) {
    await deployer.deploy(creator);
    const instance = await creator.deployed();
    const fs = require('fs');

    // Create moves
    let moveID = await instance.createMove("Fail", 500, 90);
    moveID = await instance.createMove("Change Requirements", 50, 50);
    moveID = await instance.createMove("Padlet Participation", 70, 60);
    moveID = await instance.createMove("Follow Rubric", 30, 20);
    moveID = await instance.createMove("Watch Tutorial (1)", 10, 10);
    moveID = await instance.createMove("Watch Tutorial (2)", 20, 20);
    moveID = await instance.createMove("Multi-Attack", 40, 40);
    moveID = await instance.createMove("Coding Challenge", 50, 50);

    // Create Citromon
    let citromonID = await instance.createCryptomon("Citromon", 250, 7, "0xeDE85FF88C29De2141B733BE07F2f05d03AD81c9");
    let temp = await instance.addMove(0, 0);
    temp = await instance.addMove(0, 1);
    let c = await instance.cryptomonList(0);
    const cString = "Citromon:\n" + c[4] + "\n";

    // Create Artzimon
    let ArtizmonID = await instance.createCryptomon("Artzimon", 200, 6, "0x3eA43e574B05C401A2Fac90ee681258C8d673D0d");
    temp = await instance.addMove(1, 2);
    temp = await instance.addMove(1, 3);
    let c2 = await instance.cryptomonList(1);
    const c2String = "Artzimon:\n" + c2[4] + "\n";

    // Create Sluitermon
    let sluitermonID = await instance.createCryptomon("Sluitermon", 225, 5, "0xd2d190c0E7AcC8E5E4aD0244C1bCF95EaF8D4128");
    temp = await instance.addMove(2, 4);
    temp = await instance.addMove(2, 5);
    let c3 = await instance.cryptomonList(2);
    const c3String = "Sluitermon:\n" + c3[4] + "\n";

    // Create Justomon
    let JustomonID = await instance.createCryptomon("Justomon", 200, 4, "0x0e599e21B49E98E5f1DCaA8a922dAdD6819D7018");
    temp = await instance.addMove(3, 6);
    temp = await instance.addMove(3, 7);
    let c4 = await instance.cryptomonList(3);
    const c4String = "Justomon:\n" + c4[4] + "\n";

    const s = cString + c2String + c3String + c4String;

    fs.writeFile('../Cryptomon/Cryptomon/Assets/Scripts/deploy.txt', s, err => {
        if (err) {
          console.error(err)
          return
        }
    });
};
