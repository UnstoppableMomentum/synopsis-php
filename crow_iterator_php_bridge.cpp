#include "crow_iterator_php_bridge.h"
#include "crow_php_bridge.h"

#include <base/inc/synopsis_log.h>

CRowsPhpBridgeIterator::CRowsPhpBridgeIterator(synopsis::TRows& rows)
    :m_rows(rows)
    ,m_tszCurrent(0)
{
}

CRowsPhpBridgeIterator::~CRowsPhpBridgeIterator()
{
}

Php::Value CRowsPhpBridgeIterator::currentItem()
{
    SYNOPSIS_DBG_ERR_LOG("CRowsPhpBridgeIterator::currentItem m_rows.size:%zu m_tszCurrent:%zu\n", m_rows.size(), m_tszCurrent);
    if(!isDone()) {
        synopsis::TRows::iterator iter(m_rows.begin() + m_tszCurrent);
        return Php::Object("CRow", new CRowPhpBridge(*iter));
    }
    return Php::Value();
}
