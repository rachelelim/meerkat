#include "meerkatApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "ModulesApp.h"
#include "MooseSyntax.h"

InputParameters
meerkatApp::validParams()
{
  InputParameters params = MooseApp::validParams();

  // Do not use legacy DirichletBC, that is, set DirichletBC default for preset = true
  params.set<bool>("use_legacy_dirichlet_bc") = false;

  return params;
}

meerkatApp::meerkatApp(InputParameters parameters) : MooseApp(parameters)
{
  meerkatApp::registerAll(_factory, _action_factory, _syntax);
}

meerkatApp::~meerkatApp() {}

void
meerkatApp::registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  ModulesApp::registerAll(f, af, s);
  Registry::registerObjectsTo(f, {"meerkatApp"});
  Registry::registerActionsTo(af, {"meerkatApp"});

  /* register custom execute flags, action syntax, etc. here */
}

void
meerkatApp::registerApps()
{
  registerApp(meerkatApp);
}

/***************************************************************************************************
 *********************** Dynamic Library Entry Points - DO NOT MODIFY ******************************
 **************************************************************************************************/
extern "C" void
meerkatApp__registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  meerkatApp::registerAll(f, af, s);
}
extern "C" void
meerkatApp__registerApps()
{
  meerkatApp::registerApps();
}
