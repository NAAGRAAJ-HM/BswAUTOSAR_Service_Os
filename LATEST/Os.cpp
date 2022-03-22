/******************************************************************************/
/* File   : Os.cpp                                                            */
/* Author : NAGARAJA HM (c) since 1982. All rights reserved.                  */
/******************************************************************************/

/******************************************************************************/
/* #INCLUDES                                                                  */
/******************************************************************************/
#include "module.h"
#include "Os_Cfg.h"
#include "infOs_EcuM.h"
#include "infOs_Dcm.h"
#include "infOs_SchM.h"

/******************************************************************************/
/* #DEFINES                                                                   */
/******************************************************************************/
#define OS_AR_RELEASE_MAJOR_VERSION                                            4
#define OS_AR_RELEASE_MINOR_VERSION                                            3

/******************************************************************************/
/* MACROS                                                                     */
/******************************************************************************/
#if(OS_AR_RELEASE_MAJOR_VERSION != STD_AR_RELEASE_MAJOR_VERSION)
   #error "Incompatible OS_AR_RELEASE_MAJOR_VERSION!"
#endif

#if(OS_AR_RELEASE_MINOR_VERSION != STD_AR_RELEASE_MINOR_VERSION)
   #error "Incompatible OS_AR_RELEASE_MINOR_VERSION!"
#endif

/******************************************************************************/
/* TYPEDEFS                                                                   */
/******************************************************************************/
class module_Os:
      public abstract_module
   ,  public infOs_EcuM
{
   public:
      FUNC(void, OS_CODE) InitFunction   (void);
      FUNC(void, OS_CODE) DeInitFunction (void);
      FUNC(void, OS_CODE) GetVersionInfo (void);
      FUNC(void, OS_CODE) MainFunction   (void);
      FUNC(void, OS_CODE) Start          (void);
      FUNC(void, OS_CODE) Shutdown       (void);
};

/******************************************************************************/
/* CONSTS                                                                     */
/******************************************************************************/

/******************************************************************************/
/* PARAMS                                                                     */
/******************************************************************************/

/******************************************************************************/
/* OBJECTS                                                                    */
/******************************************************************************/
VAR(module_Os, OS_VAR) Os;
CONSTP2VAR(infEcuMClient, OS_VAR, OS_CONST) gptrinfEcuMClient_Os = &Os;
CONSTP2VAR(infDcmClient,  OS_VAR, OS_CONST) gptrinfDcmClient_Os  = &Os;
CONSTP2VAR(infSchMClient, OS_VAR, OS_CONST) gptrinfSchMClient_Os = &Os;
CONSTP2VAR(infOs_EcuM,    OS_VAR, OS_CONST) gptrinfOs_EcuM       = &Os;

/******************************************************************************/
/* FUNCTIONS                                                                  */
/******************************************************************************/
#include "infSwcServiceOs_Os.h"
#include "infEcuM_Os.h"

static FUNC(void, OS_CODE) Activate_Task(void){
//TBD: <generic service> arguement must contain reference to Task

//TBD: make scope and accessibility to global

//TBD: create task for EcuM startup two operations
   gptrinfEcuM_Os->StartupTwo();
}

FUNC(void, OS_CODE) module_Os::InitFunction(void){
   Os.IsInitDone = E_OK;
}

FUNC(void, OS_CODE) module_Os::DeInitFunction(void){
   Os.IsInitDone = E_NOT_OK;
}

FUNC(void, OS_CODE) module_Os::GetVersionInfo(void){
#if(STD_ON == Os_DevErrorDetect)
//TBD: API parameter check
   Det_ReportError(
   );
#endif
}

FUNC(void, OS_CODE) module_Os::MainFunction(void){
}

FUNC(void, OS_CODE) module_Os::Start(void){
   gptrinfSwcServiceOs_Os->StartupHook();
   Activate_Task();

   while(1 /* TBD: State machine as per AUTOSAR */){
      gptrinfSwcServiceOs_Os->TASK_Idle();
   }
}

FUNC(void, OS_CODE) module_Os::Shutdown(void){
   gptrinfSwcServiceOs_Os->ShutdownHook();
}

#include "Os_Unused.h"

FUNC(void, OS_CODE) class_Os_Unused::GetResource(void){
}

FUNC(void, OS_CODE) class_Os_Unused::ReleaseResource(void){
}

FUNC(void, OS_CODE) class_Os_Unused::EnableAllInterrupts(void){
}

FUNC(void, OS_CODE) class_Os_Unused::DisableAllInterrupts(void){
}

FUNC(void, OS_CODE) class_Os_Unused::GetCurrentApplicationID(void){
}

FUNC(void, OS_CODE) class_Os_Unused::GetISRID(void){
}

FUNC(void, OS_CODE) class_Os_Unused::CallTrustedFunction(void){
}

FUNC(void, OS_CODE) class_Os_Unused::CheckISRMemoryAccess(void){
}

FUNC(void, OS_CODE) class_Os_Unused::CheckTaskMemoryAccess(void){
}

FUNC(void, OS_CODE) class_Os_Unused::CheckObjectAccess(void){
}

FUNC(void, OS_CODE) class_Os_Unused::CheckObjectOwnership(void){
}

FUNC(void, OS_CODE) class_Os_Unused::StartScheduleTableRel(void){
}

FUNC(void, OS_CODE) class_Os_Unused::StartScheduleTableAbs(void){
}

FUNC(void, OS_CODE) class_Os_Unused::StopScheduleTable(void){
}

FUNC(void, OS_CODE) class_Os_Unused::NextScheduleTable(void){
}

FUNC(void, OS_CODE) class_Os_Unused::StartScheduleTableSynchron(void){
}

FUNC(void, OS_CODE) class_Os_Unused::SyncScheduleTable(void){
}

FUNC(void, OS_CODE) class_Os_Unused::SetScheduleTableAsync(void){
}

FUNC(void, OS_CODE) class_Os_Unused::GetScheduleTableStatus(void){
}

FUNC(void, OS_CODE) class_Os_Unused::IncrementCounter(void){
}

FUNC(void, OS_CODE) class_Os_Unused::GetCounterValue(void){
}

FUNC(void, OS_CODE) class_Os_Unused::GetElapsedValue(void){
}

FUNC(void, OS_CODE) class_Os_Unused::TerminateApplication(void){
}

FUNC(void, OS_CODE) class_Os_Unused::AllowAccess(void){
}

FUNC(void, OS_CODE) class_Os_Unused::GetApplicationState(void){
}

FUNC(void, OS_CODE) class_Os_Unused::GetNumberOfActivatedCores(void){
}

FUNC(void, OS_CODE) class_Os_Unused::GetCoreId(void){
}

FUNC(void, OS_CODE) class_Os_Unused::StartCore(void){
}

FUNC(void, OS_CODE) class_Os_Unused::StartNonAutosarCore(void){
}

FUNC(void, OS_CODE) class_Os_Unused::GetSpinlock(void){
}

FUNC(void, OS_CODE) class_Os_Unused::ReleaseSpinlock(void){
}

FUNC(void, OS_CODE) class_Os_Unused::TryToGetSpinlock(void){
}

FUNC(void, OS_CODE) class_Os_Unused::ShutdownAllCores(void){
}

FUNC(void, OS_CODE) class_Os_Unused::ControlIdle(void){
}

/******************************************************************************/
/* EOF                                                                        */
/******************************************************************************/

