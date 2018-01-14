#include "Cookie.h"
#include "TEncode.h"

Cookie::Cookie(const TString cookieStr)
{
    std::vector<TString> pairslist = cookieStr.split("; ");

    for ( size_t i = 0; i < pairslist.size(); ++i )
    {
        TString name = pairslist[i].substr( 0, pairslist[i].find("=") );
        TString value = pairslist[i].substr( pairslist[i].find("=") + 1 );

//        name.replaceAll( "+", " " );
//        name = TEncode::uriDecode(name);
//        value.replaceAll( "+", " " );
//        value = TEncode::uriDecode(value);

        m_mapCookies[name] = value;
    }
}

Cookie::~Cookie()
{

}

TString Cookie::getCookie(const TString &name)
{
    if ( name != "" && m_mapCookies.find(name) != m_mapCookies.end() )
        return m_mapCookies[name];
    else
        return TString("");
}

void Cookie::setCookie(const TString &name, const TString &value)
{
    if ( name != "")
    {
        m_mapCookies[name] = value;
    }
}

void Cookie::delCookie(const TString &name)
{
    if ( name != "" && m_mapCookies.find(name) != m_mapCookies.end() )
    {
        m_mapCookies.erase(m_mapCookies.find(name));
    }
}

std::vector<TString> Cookie::toVecKeyValue()
{
    std::vector<TString> retVec;
    CookieList::iterator iterMap = m_mapCookies.begin();
    for(; iterMap != m_mapCookies.end(); iterMap++)
    {
        retVec.push_back(iterMap->first + "=" + iterMap->second);
    }
    return retVec;
}
