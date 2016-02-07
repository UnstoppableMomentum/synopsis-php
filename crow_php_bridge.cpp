#include "crow_php_bridge.h"
#include "dao_php_tools.h"
#include "cvariant_php_bridge.h"
#include <base/inc/synopsis_log.h>

CRowPhpBridge::CRowPhpBridge()
{
}

CRowPhpBridge::CRowPhpBridge(synopsis::CRow& row)
    :m_row(row)
{
}

CRowPhpBridge::~CRowPhpBridge()
{
}

void CRowPhpBridge::addColumn(Php::Parameters &params)
{
    if(2 == params.size()) {
        if(params.at(0).isString()) {
            m_row.addColumn(
                        params.at(0).stringValue(),
                        CVariantPhpBridge(params.at(1)));
        } else {
            SYNOPSIS_ERR_LOG("Invalid type of parameter[0]:%d\n", params.at(0).type());
        }
    } else {
        SYNOPSIS_ERR_LOG("Invalid number of parameters:%zu\n", params.size());
    }
}

Php::Value CRowPhpBridge::getColumnValue(Php::Parameters &params)
{
    if(1 == params.size()) {
        if(params.at(0).isString()) {
            SYNOPSIS_DBG_ERR_LOG("CRowPhpBridge::getColumnValue params.at(0):%s\n", params.at(0).stringValue().c_str());
            std::string sKey = params.at(0).stringValue();
            synopsis::CVariant varRes = m_row.getColumnValue(sKey);
            Php::Value phpRes = CVariant2PhpValue(varRes);
            return phpRes;
        } else {
            SYNOPSIS_ERR_LOG("Invalid type of parameter[0]:%d\n", params.at(0).type());
        }
    } else {
        SYNOPSIS_ERR_LOG("Invalid number of parameters:%zu\n", params.size());
    }
    return Php::Value();
}
