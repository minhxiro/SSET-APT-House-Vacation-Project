#ifndef REQUEST_H
#define REQUEST_H
#include <enum.h>
class Request {
    private:
        int request;
        int houseId;
        int tenantId;
        requestStatus status;
    public:
        Request();
        ~Request();
};
#endif