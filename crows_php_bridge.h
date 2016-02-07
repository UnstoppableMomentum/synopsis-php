#ifndef CROWS_PHP_BRIDGE_H
#define CROWS_PHP_BRIDGE_H

#include <phpcpp.h>
#include <dao/inc/row.h>
#include "crow_iterator_php_bridge.h"

class CRowsPhpBridge : public Php::Base {

public:

    CRowsPhpBridge();
    virtual ~CRowsPhpBridge();

    void pushBack(Php::Parameters &params);
    Php::Value at(Php::Parameters &params);
    Php::Value size() { return Php::Value((int64_t) m_Rows.size()); }
    inline synopsis::TRows& daoRows() { return m_Rows; }
    inline Php::Value createIterator() { return Php::Object("CRowsIterator", new CRowsPhpBridgeIterator(m_Rows)); }

private:
    synopsis::TRows m_Rows;
};

#endif // CROWS_PHP_BRIDGE_H
