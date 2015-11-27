#ifndef REACTMODULEINTERFACE_H
#define REACTMODULEINTERFACE_H

#include <functional>

#include <QtPlugin>


class ReactBridge;
class UbuntuViewManager;


class ReactModuleInterface
{
public:
  // Probably should typedef the functions generically then typedef to the block name
  // and register the generic functions with the meta system
  typedef std::function<void (ReactBridge*, const QVariantList&)> ResponseBlock;
  typedef std::function<void (ReactBridge*, const QVariantMap&)> ErrorBlock;

  virtual ~ReactModuleInterface() {}

  virtual void setBridge(ReactBridge* bridge) { Q_UNUSED(bridge); }

  // TODO: this doesnt seem right
  virtual UbuntuViewManager* viewManager() { return nullptr; }

  virtual QString moduleName() = 0;
  virtual QStringList methodsToExport() = 0;
  virtual QVariantMap constantsToExport() = 0;
};

#define ReactModuleInterface_IID "com.canonical.ReactNative.ModuleInterface"

Q_DECLARE_INTERFACE(ReactModuleInterface, ReactModuleInterface_IID);

Q_DECLARE_METATYPE(ReactModuleInterface::ResponseBlock);
Q_DECLARE_METATYPE(ReactModuleInterface::ErrorBlock);

#endif // REACTMODULEINTERFACE_H