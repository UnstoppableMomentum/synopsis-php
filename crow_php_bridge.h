#ifndef CROW_PHP_BRIDGE_H
#define CROW_PHP_BRIDGE_H

#include <phpcpp.h>
#include <dao/inc/row.h>

class CRowPhpBridge : public Php::Base {
public:

    CRowPhpBridge();
    CRowPhpBridge(synopsis::CRow& row);

    virtual ~CRowPhpBridge();

    void addColumn(Php::Parameters &params);
    Php::Value getColumnValue(Php::Parameters &params);
    void setKeyColumnName(Php::Parameters &params);
    Php::Value getKeyColumnName() const;

    synopsis::CRow& daoRow() { return m_row; }
    const synopsis::CRow& daoRow() const { return m_row; }

private:
    synopsis::CRow m_row;
};



#endif // CROW_PHP_BRIDGE_H
