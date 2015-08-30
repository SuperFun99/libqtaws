HEADERS += \
        s3storageclass_p.h \
        s3storageclass.h \
        s3response_p.h \
        s3response.h \
        s3request_p.h \
        s3request.h \
        s3putobjectresponse_p.h \
        s3putobjectresponse.h \
        s3putobjectrequest_p.h \
        s3putobjectrequest.h \
        s3objectrequest_p.h \
        s3objectrequest.h \
        s3client_p.h \
        s3client.h \
        s3cannedacl_p.h \
        s3cannedacl.h \
        s3error.h \
        s3error_p.h

SOURCES += \
        s3storageclass.cpp \
        s3response.cpp \
        s3request.cpp \
        s3putobjectresponse.cpp \
        s3putobjectrequest.cpp \
        s3objectrequest.cpp \
        s3client.cpp \
        s3cannedacl.cpp \
        s3error.cpp

VPATH += $$PWD
