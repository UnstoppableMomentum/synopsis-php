#include "crows_php_bridge.h"
#include "crow_php_bridge.h"
#include <base/inc/synopsis_log.h>

CRowsPhpBridge::CRowsPhpBridge()
{
}

CRowsPhpBridge::~CRowsPhpBridge()
{
}

void CRowsPhpBridge::pushBack(Php::Parameters &params)
{
    if(params.size() > 0) {
        if(Php::Type::Object == params.at(0).type()) {
            if(params.at(0).implementation()){
                CRowPhpBridge *pRowPhpBridge = dynamic_cast<CRowPhpBridge*>(params.at(0).implementation());
                if(pRowPhpBridge) {
                    SYNOPSIS_DBG_ERR_LOG("CRowsPhpBridge::pushBack\n");
                    m_Rows.push_back(pRowPhpBridge->daoRow());
                }
            }
        }
    }
}


Php::Value CRowsPhpBridge::at(Php::Parameters &params)
{
    SYNOPSIS_ERR_LOG("NOT IMPLEMENTED CRowsPhpBridge::at\n");
    return Php::Value();
}

