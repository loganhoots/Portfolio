const Autobot = artifacts.require("autobot");

module.exports = function (deployer) {
  deployer.deploy(Autobot);
};
