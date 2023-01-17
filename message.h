#pragma once
#include "User.h"

class Message
{
	const std::string _fromUser;
	const std::string _toUser;
	const std::string _textMessage;
public:
	Message(const std::string& fromUser, const std::string& toUser, const std::string& textMessage) : _fromUser(fromUser), _toUser(toUser), _textMessage(textMessage) {};

	const std::string& getFromUser() const { return _fromUser; }
	const std::string& getToUser() const { return _toUser; }
	const std::string& getTextMessage() const { return _textMessage; }
};