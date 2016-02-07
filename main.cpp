#include <phpcpp.h>

#include <base/inc/variant.h>
#include <dao/drivers/postgres/inc/connection_postgr.h>
#include <dao/drivers/postgres/inc/dataaccessor_postgr.h>

#include <auto_ptr.h>
#include <iostream>
#include "dao_php_tools.h"
#include "cvariant_php_bridge.h"
#include "crow_php_bridge.h"
#include "crows_php_bridge.h"
#include "crow_iterator_php_bridge.h"
/*
class CRowsPhpBridge : public Php::Base {

public:    

    CRowsPhpBridge()
    {
    }

    virtual ~CRowsPhpBridge()
    {
    }

    void pushBack(Php::Parameters &params)
    {
        std::cerr << "CRowsPhpBridge::pushBack params.size():" << params.size() << std::endl;
        if(params.size() > 0) {
            if(Php::Type::Object == params.at(0).type()) {
                std::cerr << "CRowsPhpBridge type: Object" << std::endl;
                if(params.at(0).implementation()){
                    CRowPhpBridge *pRowPhpBridge = dynamic_cast<CRowPhpBridge*>(params.at(0).implementation());
                    if(pRowPhpBridge) {
                        std::cerr << "pRowsPhpBridge::pushBack pRowPhpBridge:" << pRowPhpBridge << std::endl;
                        m_Rows.push_back(pRowPhpBridge->daoRow());
                    }
                 }
            }
        }
    }

    Php::Value size()
    {
        return Php::Value((int64_t) m_Rows.size());
    }

    Php::Value at(Php::Parameters &params)
    {
        std::cerr << "CRowsPhpBridge::at params.size():" << params.size() << std::endl;
        return Php::Value();
    }

    synopsis::TRows& daoRows()
    {
        return m_Rows;
    }

    Php::Value createIterator() {
        return Php::Object("CRowsIterator", new CRowsPhpBridgeIterator(m_Rows));
    }

private:
    synopsis::TRows m_Rows;
};
*/

/**
 *  Counter class that can be used for counting
 */
class Counter : public Php::Base
{
private:
    /**
     *  The initial value
     *  @var    int
     */
    int _value = 0;

    std::auto_ptr<synopsis::IDataAccessor> m_PtrDataAccessor;

public:
    /**
     *  C++ constructor and destructor
     */
    Counter() {}
    virtual ~Counter() {}


    /**
     *  Update methods to increment or decrement the counter
     *  Both methods return the NEW value of the counter
     *  @return int
     */

    void open(Php::Parameters &params) {
        m_PtrDataAccessor.reset(new synopsis::CDataAccessorPostgr);
        std::cerr << "open params.size():" << params.size() << std::endl;
        if(0 == params.size()) {
            m_PtrDataAccessor->GetConnection().Open("host=127.0.0.1 port=5432 dbname=dao user=postgres password=postgres");
            std::cerr << "open anonymous" << std::endl;
        }
    }

    Php::Value increment() { return ++_value; }
    Php::Value decrement() { return --_value; }
    Php::Value name() {

        CRowsPhpBridge rowsPhpBridge;
        synopsis::TRows& arrResult(rowsPhpBridge.daoRows());
        const std::string sTableName("person");
        synopsis::TStrings arrColumns;
        arrColumns.push_back("id");
        arrColumns.push_back("name");

        m_PtrDataAccessor->Read(arrResult, sTableName, arrColumns,
                                synopsis::CRow("id", 1));

        const synopsis::CRow& row = *arrResult.begin();

        return row.getColumnValue("name").ToStdString().c_str();
    }

//    virtual void Delete(const std::string& sTableName, const CRow& rowSelection = CRow()) = 0;

    void Delete (Php::Parameters &params) {
        std::cerr << "Delete params.size():" << params.size() << std::endl;
        if(params.size() > 1) {
            if(Php::Type::String == params.at(0).type()){
                if(Php::Type::Object == params.at(1).type()){
                    std::string sTableName =  params.at(0).stringValue();
                    std::cerr << "sTableName:" << sTableName << std::endl;
                    Php::Base* pBase = params.at(1).implementation();
                    std::cerr << "pBase:" << pBase << std::endl;
                    if(pBase) {
                        const CRowPhpBridge *pRowPhpBridge = dynamic_cast<const CRowPhpBridge*>(pBase);
                        std::cerr << "pRowPhpBridge:" << pRowPhpBridge << std::endl;
                        if(pRowPhpBridge)
                            m_PtrDataAccessor->Delete(sTableName, pRowPhpBridge->daoRow());
                    }
                } else {
                    std::cerr << "wrong type of param[1]:" << params.at(1).type() << std::endl;
                }
            } else {
                std::cerr << "wrong type of param[0]:" << params.at(0).type() << std::endl;
            }
        }
    }

    void insert(Php::Parameters &params) {
        std::cerr << "insert params.size():" << params.size() << std::endl;
        if(params.size() > 1) {
            if(Php::Type::String == params.at(0).type()){
                if(Php::Type::Object == params.at(1).type()){
                    std::string sTableName =  params.at(0).stringValue();
                    std::cerr << "sTableName:" << sTableName << std::endl;
                    Php::Base* pBase = params.at(1).implementation();
                    std::cerr << "pBase:" << pBase << std::endl;
                    if(pBase) {
                        const CRowPhpBridge *pRowPhpBridge = dynamic_cast<const CRowPhpBridge*>(pBase);
                        std::cerr << "pRowPhpBridge:" << pRowPhpBridge << std::endl;
                        if(pRowPhpBridge)
                            m_PtrDataAccessor->Insert(sTableName, pRowPhpBridge->daoRow());
                    }
                } else {
                    std::cerr << "wrong type of param[1]:" << params.at(1).type() << std::endl;
                }
            } else {
                std::cerr << "wrong type of param[0]:" << params.at(0).type() << std::endl;
            }
        }
    }

    void read(Php::Parameters &params) {
        std::cerr << "read params.size():" << params.size() << std::endl;
        if(params.size() > 1) {
            if(Php::Type::String == params.at(0).type()){
                if(Php::Type::Object == params.at(1).type()){
                    std::string sTableName =  params.at(0).stringValue();
                    std::cerr << "sTableName:" << sTableName << std::endl;
                    Php::Base* pBase = params.at(1).implementation();
                    std::cerr << "pBase:" << pBase << std::endl;
                    if(pBase) {
                        CRowsPhpBridge *pRowsPhpBridge = dynamic_cast<CRowsPhpBridge*>(pBase);
                        std::cerr << "pRowsPhpBridge:" << pRowsPhpBridge << std::endl;
                        m_PtrDataAccessor->Read(pRowsPhpBridge->daoRows(), sTableName);
                    }
                } else {
                    std::cerr << "wrong type of param[1]:" << params.at(1).type() << std::endl;
                }
            } else {
                std::cerr << "wrong type of param[0]:" << params.at(0).type() << std::endl;
            }
        }
    }

    Php::Value read1(Php::Parameters &params) {
        std::cerr << "open read params.size():" << params.size() << std::endl;
        if(params.size() > 0) {
            Php::Type type = params.at(0).type();
            switch (type) {
            case Php::Type::Null:
                std::cerr << "type: " << std::endl;
                //convert_to_null(_val);
                break;
            case Php::Type::Numeric:
                std::cerr << "type: " << std::endl;
                break;
            case Php::Type::Float:
                std::cerr << "type: " << std::endl;
                break;
            case Php::Type::Bool:
                std::cerr << "type: " << std::endl;
                break;
            case Php::Type::Array:
                std::cerr << "type: " << std::endl;
                break;
            case Php::Type::Object:
            {
                std::cerr << "type: Object" << std::endl;
                Php::Base* pBase = params.at(0).implementation();
                std::cerr << "pBase:" << pBase << std::endl;
                if(pBase){
                    CRowsPhpBridge *pRowsPhpBridge = dynamic_cast<CRowsPhpBridge*>(pBase);
                    std::cerr << "pRowsPhpBridge:" << pRowsPhpBridge << std::endl;
                    std::cerr << "size: " << pRowsPhpBridge->size() << std::endl;
                    if(pRowsPhpBridge->size() > 0) {
                        std::cerr << " get row" << std::endl;
                        synopsis::CRow& row = *pRowsPhpBridge->daoRows().begin();
                        std::cerr << " get column" << std::endl;
                        row.addColumn("qqq" , 1);
                        row.addColumn("www" , 22);
                    }

                }
            }
                break;
            case Php::Type::String:
                //convert_to_string(_val); break;
            case Php::Type::Resource:
                //throw FatalError("Resource types can not be handled by the PHP-CPP library");
                break;
            case Php::Type::Constant:
                //throw FatalError("Constant types can not be assigned to a PHP-CPP library variable");
                break;
            case Php::Type::ConstantArray:
                //throw FatalError("Constant types can not be assigned to a PHP-CPP library variable");
                break;
            case Php::Type::Callable:
                //throw FatalError("Callable types can not be assigned to a PHP-CPP library variable");
                break;
            }

           // std::cerr << "open read params.at(0).type():" << params.at(0).type() << std::endl;
            //CRowsPhpBridge& rowsPhpBridge = dynamic_cast<CRowsPhpBridge&>(params.at(0));
            //std::cerr << "open rowsPhpBridge.size():" << rowsPhpBridge.size() << std::endl;
            if(params.size() > 1) {

            } else if(params.size() > 2) {

            } else if(params.size() > 4) {

            } else if(params.size() > 5) {

            } else if(params.size() > 6) {

            }
        }
        return Php::Value();
//        virtual void Read(
     //   TRows& arrResult,
     //   const std::string& sTableName,
     //   const TStrings& arrColumns = TStrings(),
     //   const CRow& rowSelection = CRow(),
     //   const SelectionOrder& selectionOrder = SelectionOrder()) const = 0;

    }


    /**
     *  Method to retrieve the current counter value
     *  @return int
     */
    Php::Value value() {
        synopsis::CDataAccessorPostgr a;
        //Aqqq s;
        //s.i =111;
        m_PtrDataAccessor.reset(new synopsis::CDataAccessorPostgr);
        std::cerr << "Php::Value value 0" << std::endl;
        m_PtrDataAccessor->GetConnection().Open("host=127.0.0.1 port=5432 dbname=dao user=postgres password=postgres");
        std::cerr << "Php::Value value 2" << std::endl;

        synopsis::CRow rowNew;

        rowNew.setColumnValue("int1", 1234);
        rowNew.setColumnValue("int2", 56789);

        m_PtrDataAccessor->Insert("test", rowNew);
        // check test table row count is one
       // unsigned long ulRowCount = m_PtrDataAccessor->GetRowCount("test");


        _value = m_PtrDataAccessor->GetLastIsertedRowId("test", "id");

        // _value =s.f();
        return _value;
    }
};

/**
 *  Switch to C context to ensure that the get_module() function
 *  is callable by C programs (which the Zend engine is)
 */
extern "C" {
/**
     *  Startup function that is called by the Zend engine
     *  to retrieve all information about the extension
     *  @return void*
     */
PHPCPP_EXPORT void *get_module() {
    // create static instance of the extension object
    static Php::Extension myExtension("my_extension", "1.0");

    // description of the class so that PHP knows which methods are accessible
    Php::Class<Counter> counter("Counter");
    counter.method("increment", &Counter::increment);
    counter.method("decrement", &Counter::decrement);
    counter.method("value", &Counter::value);
    counter.method("name", &Counter::name);
    counter.method("open", &Counter::open);
    counter.method("read", &Counter::read, {
                       Php::ByVal("tablename", Php::Type::String),
                       Php::ByVal("rows", "CRows")});
    counter.method("insert", &Counter::insert, {
                       Php::ByVal("tablename", Php::Type::String),
                       Php::ByVal("row", "CRow")});
    counter.method("Delete", &Counter::Delete, {
                       Php::ByVal("tablename", Php::Type::String),
                       Php::ByVal("row", "CRow")});

    // add the class to the extension
    myExtension.add(std::move(counter));

    Php::Class<CRowPhpBridge> rowPhpBridge("CRow");
    rowPhpBridge.method("addColumn", &CRowPhpBridge::addColumn);
    rowPhpBridge.method("getColumnValue", &CRowPhpBridge::getColumnValue);
    myExtension.add(std::move(rowPhpBridge));

    Php::Class<CRowsPhpBridge> rowsPhpBridge("CRows");
    rowsPhpBridge.method("pushBack", &CRowsPhpBridge::pushBack,{ Php::ByVal("row", "CRow") });
    rowsPhpBridge.method("size", &CRowsPhpBridge::size);
    rowsPhpBridge.method("at", &CRowsPhpBridge::at);
    rowsPhpBridge.method("createIterator", &CRowsPhpBridge::createIterator);
    myExtension.add(std::move(rowsPhpBridge));

    Php::Class<CRowsPhpBridgeIterator> rowsPhpBridgeIterator("CRowsIterator");
    rowsPhpBridgeIterator.method("first", &CRowsPhpBridgeIterator::first);
    rowsPhpBridgeIterator.method("next", &CRowsPhpBridgeIterator::next);
    rowsPhpBridgeIterator.method("currentItem", &CRowsPhpBridgeIterator::currentItem);
    rowsPhpBridgeIterator.method("isDone", &CRowsPhpBridgeIterator::isDone);
    myExtension.add(std::move(rowsPhpBridgeIterator));

    // return the extension
    return myExtension;
}

} //extern "C"
