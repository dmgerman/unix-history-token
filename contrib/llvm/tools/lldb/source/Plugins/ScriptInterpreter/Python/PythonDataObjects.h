begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- PythonDataObjects.h--------------------------------------*- C++ -*-===//
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//                     The LLVM Compiler Infrastructure
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// This file is distributed under the University of Illinois Open Source
end_comment

begin_comment
comment|// License. See LICENSE.TXT for details.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//===----------------------------------------------------------------------===//
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|LLDB_PLUGINS_SCRIPTINTERPRETER_PYTHON_PYTHONDATAOBJECTS_H
end_ifndef

begin_define
define|#
directive|define
name|LLDB_PLUGINS_SCRIPTINTERPRETER_PYTHON_PYTHONDATAOBJECTS_H
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|LLDB_DISABLE_PYTHON
end_ifndef

begin_comment
comment|// LLDB Python header must be included first
end_comment

begin_include
include|#
directive|include
file|"lldb-python.h"
end_include

begin_comment
comment|// C Includes
end_comment

begin_comment
comment|// C++ Includes
end_comment

begin_comment
comment|// Other libraries and framework includes
end_comment

begin_comment
comment|// Project includes
end_comment

begin_include
include|#
directive|include
file|"lldb/Utility/Flags.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Host/File.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Interpreter/OptionValue.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Utility/ConstString.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Utility/StructuredData.h"
end_include

begin_include
include|#
directive|include
file|"lldb/lldb-defines.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/ArrayRef.h"
end_include

begin_decl_stmt
name|namespace
name|lldb_private
block|{
name|class
name|PythonBytes
decl_stmt|;
name|class
name|PythonString
decl_stmt|;
name|class
name|PythonList
decl_stmt|;
name|class
name|PythonDictionary
decl_stmt|;
name|class
name|PythonInteger
decl_stmt|;
name|class
name|StructuredPythonObject
range|:
name|public
name|StructuredData
operator|::
name|Generic
block|{
name|public
operator|:
name|StructuredPythonObject
argument_list|()
operator|:
name|StructuredData
operator|::
name|Generic
argument_list|()
block|{}
name|StructuredPythonObject
argument_list|(
name|void
operator|*
name|obj
argument_list|)
operator|:
name|StructuredData
operator|::
name|Generic
argument_list|(
argument|obj
argument_list|)
block|{
name|Py_XINCREF
argument_list|(
name|GetValue
argument_list|()
argument_list|)
block|;   }
operator|~
name|StructuredPythonObject
argument_list|()
name|override
block|{
if|if
condition|(
name|Py_IsInitialized
argument_list|()
condition|)
name|Py_XDECREF
argument_list|(
name|GetValue
argument_list|()
argument_list|)
expr_stmt|;
name|SetValue
argument_list|(
name|nullptr
argument_list|)
block|;   }
name|bool
name|IsValid
argument_list|()
specifier|const
name|override
block|{
return|return
name|GetValue
argument_list|()
operator|&&
name|GetValue
argument_list|()
operator|!=
name|Py_None
return|;
block|}
name|void
name|Dump
argument_list|(
name|Stream
operator|&
name|s
argument_list|,
name|bool
name|pretty_print
operator|=
name|true
argument_list|)
decl|const
name|override
decl_stmt|;
name|private
label|:
name|DISALLOW_COPY_AND_ASSIGN
argument_list|(
name|StructuredPythonObject
argument_list|)
expr_stmt|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_decl_stmt
name|enum
name|class
name|PyObjectType
block|{
name|Unknown
operator|,
name|None
operator|,
name|Integer
operator|,
name|Dictionary
operator|,
name|List
operator|,
name|String
operator|,
name|Bytes
operator|,
name|ByteArray
operator|,
name|Module
operator|,
name|Callable
operator|,
name|Tuple
operator|,
name|File
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_decl_stmt
name|enum
name|class
name|PyRefType
block|{
name|Borrowed
operator|,
comment|// We are not given ownership of the incoming PyObject.
comment|// We cannot safely hold it without calling Py_INCREF.
name|Owned
comment|// We have ownership of the incoming PyObject.  We should
comment|// not call Py_INCREF.
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_decl_stmt
name|enum
name|class
name|PyInitialValue
block|{
name|Invalid
operator|,
name|Empty
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_decl_stmt
name|class
name|PythonObject
block|{
name|public
label|:
name|PythonObject
argument_list|()
operator|:
name|m_py_obj
argument_list|(
argument|nullptr
argument_list|)
block|{}
name|PythonObject
argument_list|(
argument|PyRefType type
argument_list|,
argument|PyObject *py_obj
argument_list|)
operator|:
name|m_py_obj
argument_list|(
argument|nullptr
argument_list|)
block|{
name|Reset
argument_list|(
name|type
argument_list|,
name|py_obj
argument_list|)
block|;   }
name|PythonObject
argument_list|(
specifier|const
name|PythonObject
operator|&
name|rhs
argument_list|)
operator|:
name|m_py_obj
argument_list|(
argument|nullptr
argument_list|)
block|{
name|Reset
argument_list|(
name|rhs
argument_list|)
block|; }
name|virtual
operator|~
name|PythonObject
argument_list|()
block|{
name|Reset
argument_list|()
block|; }
name|void
name|Reset
argument_list|()
block|{
comment|// Avoid calling the virtual method since it's not necessary
comment|// to actually validate the type of the PyObject if we're
comment|// just setting to null.
if|if
condition|(
name|Py_IsInitialized
argument_list|()
condition|)
name|Py_XDECREF
argument_list|(
name|m_py_obj
argument_list|)
expr_stmt|;
name|m_py_obj
operator|=
name|nullptr
expr_stmt|;
block|}
end_decl_stmt

begin_function
name|void
name|Reset
parameter_list|(
specifier|const
name|PythonObject
modifier|&
name|rhs
parameter_list|)
block|{
comment|// Avoid calling the virtual method if it's not necessary
comment|// to actually validate the type of the PyObject.
if|if
condition|(
operator|!
name|rhs
operator|.
name|IsValid
argument_list|()
condition|)
name|Reset
argument_list|()
expr_stmt|;
else|else
name|Reset
argument_list|(
name|PyRefType
operator|::
name|Borrowed
argument_list|,
name|rhs
operator|.
name|m_py_obj
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|// PythonObject is implicitly convertible to PyObject *, which will call the
end_comment

begin_comment
comment|// wrong overload.  We want to explicitly disallow this, since a PyObject
end_comment

begin_comment
comment|// *always* owns its reference.  Therefore the overload which takes a
end_comment

begin_comment
comment|// PyRefType doesn't make sense, and the copy constructor should be used.
end_comment

begin_function_decl
name|void
name|Reset
parameter_list|(
name|PyRefType
name|type
parameter_list|,
specifier|const
name|PythonObject
modifier|&
name|ref
parameter_list|)
init|=
name|delete
function_decl|;
end_function_decl

begin_function
name|virtual
name|void
name|Reset
parameter_list|(
name|PyRefType
name|type
parameter_list|,
name|PyObject
modifier|*
name|py_obj
parameter_list|)
block|{
if|if
condition|(
name|py_obj
operator|==
name|m_py_obj
condition|)
return|return;
if|if
condition|(
name|Py_IsInitialized
argument_list|()
condition|)
name|Py_XDECREF
argument_list|(
name|m_py_obj
argument_list|)
expr_stmt|;
name|m_py_obj
operator|=
name|py_obj
expr_stmt|;
comment|// If this is a borrowed reference, we need to convert it to
comment|// an owned reference by incrementing it.  If it is an owned
comment|// reference (for example the caller allocated it with PyDict_New()
comment|// then we must *not* increment it.
if|if
condition|(
name|Py_IsInitialized
argument_list|()
operator|&&
name|type
operator|==
name|PyRefType
operator|::
name|Borrowed
condition|)
name|Py_XINCREF
argument_list|(
name|m_py_obj
argument_list|)
expr_stmt|;
block|}
end_function

begin_expr_stmt
name|void
name|Dump
argument_list|()
specifier|const
block|{
if|if
condition|(
name|m_py_obj
condition|)
name|_PyObject_Dump
argument_list|(
name|m_py_obj
argument_list|)
expr_stmt|;
else|else
name|puts
argument_list|(
literal|"NULL"
argument_list|)
expr_stmt|;
block|}
end_expr_stmt

begin_decl_stmt
name|void
name|Dump
argument_list|(
name|Stream
operator|&
name|strm
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|PyObject
operator|*
name|get
argument_list|()
specifier|const
block|{
return|return
name|m_py_obj
return|;
block|}
end_expr_stmt

begin_function
name|PyObject
modifier|*
name|release
parameter_list|()
block|{
name|PyObject
modifier|*
name|result
init|=
name|m_py_obj
decl_stmt|;
name|m_py_obj
operator|=
name|nullptr
expr_stmt|;
return|return
name|result
return|;
block|}
end_function

begin_decl_stmt
name|PythonObject
modifier|&
name|operator
init|=
operator|(
specifier|const
name|PythonObject
operator|&
name|other
operator|)
block|{
name|Reset
argument_list|(
name|PyRefType
operator|::
name|Borrowed
argument_list|,
name|other
operator|.
name|get
argument_list|()
argument_list|)
block|;
return|return
operator|*
name|this
return|;
block|}
end_decl_stmt

begin_expr_stmt
name|PyObjectType
name|GetObjectType
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|PythonString
name|Repr
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|PythonString
name|Str
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt

begin_decl_stmt
specifier|static
name|PythonObject
name|ResolveNameWithDictionary
argument_list|(
name|llvm
operator|::
name|StringRef
name|name
argument_list|,
specifier|const
name|PythonDictionary
operator|&
name|dict
argument_list|)
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|template
operator|<
name|typename
name|T
operator|>
specifier|static
name|T
name|ResolveNameWithDictionary
argument_list|(
argument|llvm::StringRef name
argument_list|,
argument|const PythonDictionary&dict
argument_list|)
block|{
return|return
name|ResolveNameWithDictionary
argument_list|(
name|name
argument_list|,
name|dict
argument_list|)
operator|.
name|AsType
operator|<
name|T
operator|>
operator|(
operator|)
return|;
block|}
end_expr_stmt

begin_decl_stmt
name|PythonObject
name|ResolveName
argument_list|(
name|llvm
operator|::
name|StringRef
name|name
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|template
operator|<
name|typename
name|T
operator|>
name|T
name|ResolveName
argument_list|(
argument|llvm::StringRef name
argument_list|)
specifier|const
block|{
return|return
name|ResolveName
argument_list|(
name|name
argument_list|)
operator|.
name|AsType
operator|<
name|T
operator|>
operator|(
operator|)
return|;
block|}
end_expr_stmt

begin_decl_stmt
name|bool
name|HasAttribute
argument_list|(
name|llvm
operator|::
name|StringRef
name|attribute
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|PythonObject
name|GetAttributeValue
argument_list|(
name|llvm
operator|::
name|StringRef
name|attribute
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|bool
name|IsValid
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|bool
name|IsAllocated
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|bool
name|IsNone
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|template
operator|<
name|typename
name|T
operator|>
name|T
name|AsType
argument_list|()
specifier|const
block|{
if|if
condition|(
operator|!
name|T
operator|::
name|Check
argument_list|(
name|m_py_obj
argument_list|)
condition|)
return|return
name|T
argument_list|()
return|;
end_expr_stmt

begin_return
return|return
name|T
argument_list|(
name|PyRefType
operator|::
name|Borrowed
argument_list|,
name|m_py_obj
argument_list|)
return|;
end_return

begin_expr_stmt
unit|}    StructuredData
operator|::
name|ObjectSP
name|CreateStructuredObject
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt

begin_label
name|protected
label|:
end_label

begin_decl_stmt
name|PyObject
modifier|*
name|m_py_obj
decl_stmt|;
end_decl_stmt

begin_decl_stmt
unit|};
name|class
name|PythonBytes
range|:
name|public
name|PythonObject
block|{
name|public
operator|:
name|PythonBytes
argument_list|()
block|;
name|explicit
name|PythonBytes
argument_list|(
name|llvm
operator|::
name|ArrayRef
operator|<
name|uint8_t
operator|>
name|bytes
argument_list|)
block|;
name|PythonBytes
argument_list|(
argument|const uint8_t *bytes
argument_list|,
argument|size_t length
argument_list|)
block|;
name|PythonBytes
argument_list|(
argument|PyRefType type
argument_list|,
argument|PyObject *o
argument_list|)
block|;
name|PythonBytes
argument_list|(
specifier|const
name|PythonBytes
operator|&
name|object
argument_list|)
block|;
operator|~
name|PythonBytes
argument_list|()
name|override
block|;
specifier|static
name|bool
name|Check
argument_list|(
name|PyObject
operator|*
name|py_obj
argument_list|)
block|;
comment|// Bring in the no-argument base class version
name|using
name|PythonObject
operator|::
name|Reset
block|;
name|void
name|Reset
argument_list|(
argument|PyRefType type
argument_list|,
argument|PyObject *py_obj
argument_list|)
name|override
block|;
name|llvm
operator|::
name|ArrayRef
operator|<
name|uint8_t
operator|>
name|GetBytes
argument_list|()
specifier|const
block|;
name|size_t
name|GetSize
argument_list|()
specifier|const
block|;
name|void
name|SetBytes
argument_list|(
name|llvm
operator|::
name|ArrayRef
operator|<
name|uint8_t
operator|>
name|stringbytes
argument_list|)
block|;
name|StructuredData
operator|::
name|StringSP
name|CreateStructuredString
argument_list|()
specifier|const
block|; }
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|class
name|PythonByteArray
range|:
name|public
name|PythonObject
block|{
name|public
operator|:
name|PythonByteArray
argument_list|()
block|;
name|explicit
name|PythonByteArray
argument_list|(
name|llvm
operator|::
name|ArrayRef
operator|<
name|uint8_t
operator|>
name|bytes
argument_list|)
block|;
name|PythonByteArray
argument_list|(
argument|const uint8_t *bytes
argument_list|,
argument|size_t length
argument_list|)
block|;
name|PythonByteArray
argument_list|(
argument|PyRefType type
argument_list|,
argument|PyObject *o
argument_list|)
block|;
name|PythonByteArray
argument_list|(
specifier|const
name|PythonBytes
operator|&
name|object
argument_list|)
block|;
operator|~
name|PythonByteArray
argument_list|()
name|override
block|;
specifier|static
name|bool
name|Check
argument_list|(
name|PyObject
operator|*
name|py_obj
argument_list|)
block|;
comment|// Bring in the no-argument base class version
name|using
name|PythonObject
operator|::
name|Reset
block|;
name|void
name|Reset
argument_list|(
argument|PyRefType type
argument_list|,
argument|PyObject *py_obj
argument_list|)
name|override
block|;
name|llvm
operator|::
name|ArrayRef
operator|<
name|uint8_t
operator|>
name|GetBytes
argument_list|()
specifier|const
block|;
name|size_t
name|GetSize
argument_list|()
specifier|const
block|;
name|void
name|SetBytes
argument_list|(
name|llvm
operator|::
name|ArrayRef
operator|<
name|uint8_t
operator|>
name|stringbytes
argument_list|)
block|;
name|StructuredData
operator|::
name|StringSP
name|CreateStructuredString
argument_list|()
specifier|const
block|; }
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|class
name|PythonString
range|:
name|public
name|PythonObject
block|{
name|public
operator|:
name|PythonString
argument_list|()
block|;
name|explicit
name|PythonString
argument_list|(
argument|llvm::StringRef string
argument_list|)
block|;
name|explicit
name|PythonString
argument_list|(
specifier|const
name|char
operator|*
name|string
argument_list|)
block|;
name|PythonString
argument_list|(
argument|PyRefType type
argument_list|,
argument|PyObject *o
argument_list|)
block|;
name|PythonString
argument_list|(
specifier|const
name|PythonString
operator|&
name|object
argument_list|)
block|;
operator|~
name|PythonString
argument_list|()
name|override
block|;
specifier|static
name|bool
name|Check
argument_list|(
name|PyObject
operator|*
name|py_obj
argument_list|)
block|;
comment|// Bring in the no-argument base class version
name|using
name|PythonObject
operator|::
name|Reset
block|;
name|void
name|Reset
argument_list|(
argument|PyRefType type
argument_list|,
argument|PyObject *py_obj
argument_list|)
name|override
block|;
name|llvm
operator|::
name|StringRef
name|GetString
argument_list|()
specifier|const
block|;
name|size_t
name|GetSize
argument_list|()
specifier|const
block|;
name|void
name|SetString
argument_list|(
argument|llvm::StringRef string
argument_list|)
block|;
name|StructuredData
operator|::
name|StringSP
name|CreateStructuredString
argument_list|()
specifier|const
block|; }
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|class
name|PythonInteger
range|:
name|public
name|PythonObject
block|{
name|public
operator|:
name|PythonInteger
argument_list|()
block|;
name|explicit
name|PythonInteger
argument_list|(
argument|int64_t value
argument_list|)
block|;
name|PythonInteger
argument_list|(
argument|PyRefType type
argument_list|,
argument|PyObject *o
argument_list|)
block|;
name|PythonInteger
argument_list|(
specifier|const
name|PythonInteger
operator|&
name|object
argument_list|)
block|;
operator|~
name|PythonInteger
argument_list|()
name|override
block|;
specifier|static
name|bool
name|Check
argument_list|(
name|PyObject
operator|*
name|py_obj
argument_list|)
block|;
comment|// Bring in the no-argument base class version
name|using
name|PythonObject
operator|::
name|Reset
block|;
name|void
name|Reset
argument_list|(
argument|PyRefType type
argument_list|,
argument|PyObject *py_obj
argument_list|)
name|override
block|;
name|int64_t
name|GetInteger
argument_list|()
specifier|const
block|;
name|void
name|SetInteger
argument_list|(
argument|int64_t value
argument_list|)
block|;
name|StructuredData
operator|::
name|IntegerSP
name|CreateStructuredInteger
argument_list|()
specifier|const
block|; }
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|class
name|PythonList
range|:
name|public
name|PythonObject
block|{
name|public
operator|:
name|PythonList
argument_list|()
block|{}
name|explicit
name|PythonList
argument_list|(
argument|PyInitialValue value
argument_list|)
block|;
name|explicit
name|PythonList
argument_list|(
argument|int list_size
argument_list|)
block|;
name|PythonList
argument_list|(
argument|PyRefType type
argument_list|,
argument|PyObject *o
argument_list|)
block|;
name|PythonList
argument_list|(
specifier|const
name|PythonList
operator|&
name|list
argument_list|)
block|;
operator|~
name|PythonList
argument_list|()
name|override
block|;
specifier|static
name|bool
name|Check
argument_list|(
name|PyObject
operator|*
name|py_obj
argument_list|)
block|;
comment|// Bring in the no-argument base class version
name|using
name|PythonObject
operator|::
name|Reset
block|;
name|void
name|Reset
argument_list|(
argument|PyRefType type
argument_list|,
argument|PyObject *py_obj
argument_list|)
name|override
block|;
name|uint32_t
name|GetSize
argument_list|()
specifier|const
block|;
name|PythonObject
name|GetItemAtIndex
argument_list|(
argument|uint32_t index
argument_list|)
specifier|const
block|;
name|void
name|SetItemAtIndex
argument_list|(
argument|uint32_t index
argument_list|,
argument|const PythonObject&object
argument_list|)
block|;
name|void
name|AppendItem
argument_list|(
specifier|const
name|PythonObject
operator|&
name|object
argument_list|)
block|;
name|StructuredData
operator|::
name|ArraySP
name|CreateStructuredArray
argument_list|()
specifier|const
block|; }
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|class
name|PythonTuple
range|:
name|public
name|PythonObject
block|{
name|public
operator|:
name|PythonTuple
argument_list|()
block|{}
name|explicit
name|PythonTuple
argument_list|(
argument|PyInitialValue value
argument_list|)
block|;
name|explicit
name|PythonTuple
argument_list|(
argument|int tuple_size
argument_list|)
block|;
name|PythonTuple
argument_list|(
argument|PyRefType type
argument_list|,
argument|PyObject *o
argument_list|)
block|;
name|PythonTuple
argument_list|(
specifier|const
name|PythonTuple
operator|&
name|tuple
argument_list|)
block|;
name|PythonTuple
argument_list|(
name|std
operator|::
name|initializer_list
operator|<
name|PythonObject
operator|>
name|objects
argument_list|)
block|;
name|PythonTuple
argument_list|(
name|std
operator|::
name|initializer_list
operator|<
name|PyObject
operator|*
operator|>
name|objects
argument_list|)
block|;
operator|~
name|PythonTuple
argument_list|()
name|override
block|;
specifier|static
name|bool
name|Check
argument_list|(
name|PyObject
operator|*
name|py_obj
argument_list|)
block|;
comment|// Bring in the no-argument base class version
name|using
name|PythonObject
operator|::
name|Reset
block|;
name|void
name|Reset
argument_list|(
argument|PyRefType type
argument_list|,
argument|PyObject *py_obj
argument_list|)
name|override
block|;
name|uint32_t
name|GetSize
argument_list|()
specifier|const
block|;
name|PythonObject
name|GetItemAtIndex
argument_list|(
argument|uint32_t index
argument_list|)
specifier|const
block|;
name|void
name|SetItemAtIndex
argument_list|(
argument|uint32_t index
argument_list|,
argument|const PythonObject&object
argument_list|)
block|;
name|StructuredData
operator|::
name|ArraySP
name|CreateStructuredArray
argument_list|()
specifier|const
block|; }
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|class
name|PythonDictionary
range|:
name|public
name|PythonObject
block|{
name|public
operator|:
name|PythonDictionary
argument_list|()
block|{}
name|explicit
name|PythonDictionary
argument_list|(
argument|PyInitialValue value
argument_list|)
block|;
name|PythonDictionary
argument_list|(
argument|PyRefType type
argument_list|,
argument|PyObject *o
argument_list|)
block|;
name|PythonDictionary
argument_list|(
specifier|const
name|PythonDictionary
operator|&
name|dict
argument_list|)
block|;
operator|~
name|PythonDictionary
argument_list|()
name|override
block|;
specifier|static
name|bool
name|Check
argument_list|(
name|PyObject
operator|*
name|py_obj
argument_list|)
block|;
comment|// Bring in the no-argument base class version
name|using
name|PythonObject
operator|::
name|Reset
block|;
name|void
name|Reset
argument_list|(
argument|PyRefType type
argument_list|,
argument|PyObject *py_obj
argument_list|)
name|override
block|;
name|uint32_t
name|GetSize
argument_list|()
specifier|const
block|;
name|PythonList
name|GetKeys
argument_list|()
specifier|const
block|;
name|PythonObject
name|GetItemForKey
argument_list|(
argument|const PythonObject&key
argument_list|)
specifier|const
block|;
name|void
name|SetItemForKey
argument_list|(
specifier|const
name|PythonObject
operator|&
name|key
argument_list|,
specifier|const
name|PythonObject
operator|&
name|value
argument_list|)
block|;
name|StructuredData
operator|::
name|DictionarySP
name|CreateStructuredDictionary
argument_list|()
specifier|const
block|; }
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|class
name|PythonModule
range|:
name|public
name|PythonObject
block|{
name|public
operator|:
name|PythonModule
argument_list|()
block|;
name|PythonModule
argument_list|(
argument|PyRefType type
argument_list|,
argument|PyObject *o
argument_list|)
block|;
name|PythonModule
argument_list|(
specifier|const
name|PythonModule
operator|&
name|dict
argument_list|)
block|;
operator|~
name|PythonModule
argument_list|()
name|override
block|;
specifier|static
name|bool
name|Check
argument_list|(
name|PyObject
operator|*
name|py_obj
argument_list|)
block|;
specifier|static
name|PythonModule
name|BuiltinsModule
argument_list|()
block|;
specifier|static
name|PythonModule
name|MainModule
argument_list|()
block|;
specifier|static
name|PythonModule
name|AddModule
argument_list|(
argument|llvm::StringRef module
argument_list|)
block|;
specifier|static
name|PythonModule
name|ImportModule
argument_list|(
argument|llvm::StringRef module
argument_list|)
block|;
comment|// Bring in the no-argument base class version
name|using
name|PythonObject
operator|::
name|Reset
block|;
name|void
name|Reset
argument_list|(
argument|PyRefType type
argument_list|,
argument|PyObject *py_obj
argument_list|)
name|override
block|;
name|PythonDictionary
name|GetDictionary
argument_list|()
specifier|const
block|; }
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|class
name|PythonCallable
range|:
name|public
name|PythonObject
block|{
name|public
operator|:
expr|struct
name|ArgInfo
block|{
name|size_t
name|count
block|;
name|bool
name|is_bound_method
operator|:
literal|1
block|;
name|bool
name|has_varargs
operator|:
literal|1
block|;
name|bool
name|has_kwargs
operator|:
literal|1
block|;   }
block|;
name|PythonCallable
argument_list|()
block|;
name|PythonCallable
argument_list|(
argument|PyRefType type
argument_list|,
argument|PyObject *o
argument_list|)
block|;
name|PythonCallable
argument_list|(
specifier|const
name|PythonCallable
operator|&
name|dict
argument_list|)
block|;
operator|~
name|PythonCallable
argument_list|()
name|override
block|;
specifier|static
name|bool
name|Check
argument_list|(
name|PyObject
operator|*
name|py_obj
argument_list|)
block|;
comment|// Bring in the no-argument base class version
name|using
name|PythonObject
operator|::
name|Reset
block|;
name|void
name|Reset
argument_list|(
argument|PyRefType type
argument_list|,
argument|PyObject *py_obj
argument_list|)
name|override
block|;
name|ArgInfo
name|GetNumArguments
argument_list|()
specifier|const
block|;
name|PythonObject
name|operator
argument_list|()
argument_list|()
block|;
name|PythonObject
name|operator
argument_list|()
argument_list|(
name|std
operator|::
name|initializer_list
operator|<
name|PyObject
operator|*
operator|>
name|args
argument_list|)
block|;
name|PythonObject
name|operator
argument_list|()
argument_list|(
name|std
operator|::
name|initializer_list
operator|<
name|PythonObject
operator|>
name|args
argument_list|)
block|;
name|template
operator|<
name|typename
name|Arg
block|,
name|typename
operator|...
name|Args
operator|>
name|PythonObject
name|operator
argument_list|()
operator|(
specifier|const
name|Arg
operator|&
name|arg
expr|,
name|Args
operator|...
name|args
operator|)
block|{
return|return
name|operator
argument_list|()
argument_list|(
block|{
name|arg
operator|,
name|args
operator|...
block|}
block|)
block|;   }
end_decl_stmt

begin_decl_stmt
unit|};
name|class
name|PythonFile
range|:
name|public
name|PythonObject
block|{
name|public
operator|:
name|PythonFile
argument_list|()
block|;
name|PythonFile
argument_list|(
name|File
operator|&
name|file
argument_list|,
specifier|const
name|char
operator|*
name|mode
argument_list|)
block|;
name|PythonFile
argument_list|(
specifier|const
name|char
operator|*
name|path
argument_list|,
specifier|const
name|char
operator|*
name|mode
argument_list|)
block|;
name|PythonFile
argument_list|(
argument|PyRefType type
argument_list|,
argument|PyObject *o
argument_list|)
block|;
operator|~
name|PythonFile
argument_list|()
name|override
block|;
specifier|static
name|bool
name|Check
argument_list|(
name|PyObject
operator|*
name|py_obj
argument_list|)
block|;
name|using
name|PythonObject
operator|::
name|Reset
block|;
name|void
name|Reset
argument_list|(
argument|PyRefType type
argument_list|,
argument|PyObject *py_obj
argument_list|)
name|override
block|;
name|void
name|Reset
argument_list|(
name|File
operator|&
name|file
argument_list|,
specifier|const
name|char
operator|*
name|mode
argument_list|)
block|;
specifier|static
name|uint32_t
name|GetOptionsFromMode
argument_list|(
argument|llvm::StringRef mode
argument_list|)
block|;
name|bool
name|GetUnderlyingFile
argument_list|(
argument|File&file
argument_list|)
specifier|const
block|; }
decl_stmt|;
end_decl_stmt

begin_comment
unit|}
comment|// namespace lldb_private
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// LLDB_PLUGINS_SCRIPTINTERPRETER_PYTHON_PYTHONDATAOBJECTS_H
end_comment

end_unit

