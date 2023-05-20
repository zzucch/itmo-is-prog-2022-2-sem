#ifndef INC_4_IFIGURE_H_
#define INC_4_IFIGURE_H_

#include <vector>
#include "classes_from_task/IGeoFig.h"
#include "classes_from_task/IPhysObject.h"
#include "classes_from_task/IPrintable.h"
#include "classes_from_task/IDialogInitiable.h"
#include "classes_from_task/BaseCObject.h"

class IFigure
    : public IGeoFig,
      public IPhysObject,
      public IPrintable,
      public IDialogInitiable,
      public BaseCObject {
};

#endif //INC_4_IFIGURE_H_
