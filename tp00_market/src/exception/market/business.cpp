#include "business.h"

NonExistentParticipantException::NonExistentParticipantException(int id, const std::string &error) :
		std::invalid_argument("Participant " + std::to_string(id) + ": " + error), id(id), error(error) {}

UnavailableProductException::UnavailableProductException(int id, const std::string &error) :
		std::invalid_argument(std::to_string(id) + ". " + error), id(id), error(error) {}
