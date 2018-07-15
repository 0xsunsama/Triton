//! \file
/*
**  Copyright (C) - Triton
**
**  This program is under the terms of the BSD License.
*/

#include <triton/pythonBindings.hpp>
#include <triton/pythonUtils.hpp>
#include <triton/pythonXFunctions.hpp>
#include <triton/operandInterface.hpp>



/*! \page py_OPERAND_page OPERAND
    \brief [**python api**] All information about the OPERAND python namespace.

\tableofcontents

\section OPERAND_py_description Description
<hr>

The OPERAND namespace contains all kinds of operand.

\section OPERAND_py_api Python API - Items of the OPERAND namespace
<hr>

- **OPERAND.INVALID**
- **OPERAND.IMM**
- **OPERAND.MEM**
- **OPERAND.REG**

*/



namespace triton {
  namespace bindings {
    namespace python {

#ifdef IS_PY3
      NAMESPACE_TYPE(OPERAND, OperandNamespace)

      PyObject* initOperandNamespace() {
        PyType_Ready(&OperandNamespace_Type);
        PyObject *operandDict = OperandNamespace_Type.tp_dict;
#else
      void initOperandNamespace(PyObject* operandDict) {
#endif
        xPyDict_SetItemString(operandDict, "INVALID",  PyLong_FromUint32(triton::arch::OP_INVALID));
        xPyDict_SetItemString(operandDict, "IMM",      PyLong_FromUint32(triton::arch::OP_IMM));
        xPyDict_SetItemString(operandDict, "MEM",      PyLong_FromUint32(triton::arch::OP_MEM));
        xPyDict_SetItemString(operandDict, "REG",      PyLong_FromUint32(triton::arch::OP_REG));
#ifdef IS_PY3
        return _PyObject_New(&OperandNamespace_Type);
#endif
      }

    }; /* python namespace */
  }; /* bindings namespace */
}; /* triton namespace */
