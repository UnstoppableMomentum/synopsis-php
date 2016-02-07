#ifndef CVARIANT_PHP_BRIDGE_H
#define CVARIANT_PHP_BRIDGE_H

#include <phpcpp.h>
#include <base/inc/variant.h>

class CVariantPhpBridge : public synopsis::CVariant {
public:
    explicit CVariantPhpBridge (const Php::Value& val);    
};


#endif // CVARIANT_PHP_BRIDGE_H
