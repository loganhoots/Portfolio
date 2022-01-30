// SPDX-License-Identifier: MIT
pragma solidity ^0.8.11;

contract User { 
    address public user_;
    bool authentication;
    string public password;

    constructor(string memory password_) { //contruct that connects users to the contract
        user_ = msg.sender;
        password = password_;
    }

    function authenticator(string memory password_) public view returns (bool) { //creates the password for each user
        if (keccak256(abi.encodePacked((password))) == keccak256(abi.encodePacked((password_)))) {
            return true;
        }
        return false;
    }
}