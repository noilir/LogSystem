#ifndef APPENDER_H
#define APPENDER_H
/*INCLUSIONS*/
#include <string>
class Logger;
enum LogLevel;
/*FIN INCLUSIONS*/
class LogContent;
/*
@enum AppenderFlag
@brief enumeration des flag que peuvent avoir les appenders
*/
enum AppenderFlag
{


};
/*
@enum AppenderType
@brief enumeration utilisée pour la copie des Appender
*/
enum AppenderType
{
	CONSOLE_APPENDER
};
class Appender
{
public:
    /*
    @fn Appender(const std::string& name,LogLevel level)
    @params name reference constante sur une chaine de caractere representant le nom de l'appender
            level le niveau minimum de log
    @brief constructeur
    @return no return
    */
    Appender(const std::string& name, LogLevel level);
    /*
    @fn Appender(const Appender& coy)
    @params copy une reference constante sur un objet Appender à copier
    @brief constructeur de copie
    @return no return
    */
    Appender(const Appender& copy);
    /*
    @fn Appender(Appender&& moved)
    @params moved une reference de deplacement sur un objet Appender à déplacer
    @brief constructeur de déplacement
    @return no return
    */
    Appender(Appender&& moved);
    /*
    @fn ~Appender()
    @params no params
    @brief destructeur
    @return no return
    */
    ~Appender();
    /*
    @fn bool shouldLogLevel(LogLevel levelToLog)
    @params levelToLog le niveau de log à vérifier
    @brief methode permettant de vérifier si un niveau de log est accepté ou non
    @return bool
    */
    bool shouldLogLevel(LogLevel levelToLog);
    /*
    @fn virtual void write(LogContent& content)=0
    @params content une reference sur un objet LogContent à traiter
    @brief methode permettant de traiter un objet LogContent
    @return void
    */
    virtual void write(LogContent& content)=0;
    /*
    @fn const std::string& getName() const
    @params no params
    @brief methode retournant le nom de l'appender
    return const std::string&
    */
    const std::string& getName() const;
	/*
	@fn const AppenderType& getType() const
	@params no params
	@brief methode retournant le type de l'appender
	return const AppenderType&
	*/
	const AppenderType& getType() const;
protected:
    /*le niveau minimum de log*/
    LogLevel _minLogLevel;
    /*le nom de l'appender*/
    std::string _name;
	/*le type d'appender*/
	AppenderType _appenderType;

};
#endif
