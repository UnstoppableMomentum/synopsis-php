#include "dao_php_tools.h"

Php::Value CVariant2PhpValue(synopsis::CVariant& val) {

    switch (val.Type()) {
        case synopsis::ECommonTypeBool:
            return Php::Value(val.ToBool());
        break;
        case synopsis::ECommonTypeInt:
            return Php::Value((int64_t) val.ToInt());
        break;
        case synopsis::ECommonTypeULong:
            return Php::Value((int64_t) val.ToULong());
        break;
        case synopsis::ECommonTypeDouble:
            return Php::Value(val.ToDouble());
        break;
        case synopsis::ECommonTypeFloat:
            return Php::Value(val.ToDouble());
        break;
        case synopsis::ECommonTypeDate:
        break;
        case synopsis::ECommonTypeTime:
        break;
        case synopsis::ECommonTypeDateTime:
        break;
        case synopsis::ECommonTypeStdString:
            return Php::Value(val.ToStdString());
        break;
        default:
            return Php::Value();
        break;
    }
    return Php::Value();
}
