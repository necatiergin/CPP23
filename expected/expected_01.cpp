#include <expected>

enum class HttpError {
	BadRequest = 400,
	Unauthorized = 401,ac
	Forbidden = 403,
	NotFound = 404
};

struct OrderInfo {
	//...
};

std::expected<OrderInfo, HttpError> getOrderValues(/* */);
