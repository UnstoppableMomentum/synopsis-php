#include "cvariant_php_bridge.h"
#include <iostream>

CVariantPhpBridge::CVariantPhpBridge (const Php::Value& val)
{
    std::cerr << "CVariantPhpBridge::CVariantPhpBridge" << std::endl;
    if(val.isNumeric()) {
        std::cerr << "CVariantPhpBridge::CVariantPhpBridge val.isNumeric()" << std::endl;
        m_uData.i = val.numericValue();        
        SetType(synopsis::ECommonTypeInt);
        SetValid(true);
        SetIsNull(false);
    } else if(val.isBool()) {
        std::cerr << "CVariantPhpBridge::CVariantPhpBridge val.isBool()" << std::endl;
        m_uData.b = val.boolValue();
        SetType(synopsis::ECommonTypeBool);
        SetValid(true);
        SetIsNull(false);
    } else if(val.isString()) {
        std::cerr << "CVariantPhpBridge::CVariantPhpBridge val.isString()" << std::endl;
        m_sData =val.stringValue();
        SetType(synopsis::ECommonTypeStdString);
        SetValid(true);
        SetIsNull(false);
    } else if(val.isFloat()) {
        std::cerr << "CVariantPhpBridge::CVariantPhpBridge val.isFloat()" << std::endl;
        m_uData.d = val.floatValue();
        SetType(synopsis::ECommonTypeDouble);
        SetValid(true);
        SetIsNull(false);
    }
}
