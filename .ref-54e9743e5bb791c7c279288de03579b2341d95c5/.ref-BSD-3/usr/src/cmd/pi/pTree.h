begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*      *	pTree.h      *      *	global declarations for copying pi trees to pTrees      */
end_comment

begin_include
include|#
directive|include
file|<pAddr.h>
end_include

begin_include
include|#
directive|include
file|"pTags.h"
end_include

begin_comment
comment|/*      *	stack of nested program/procedure/function declaration pNodes      *	and a stack pointer      */
end_comment

begin_define
define|#
directive|define
name|MAXNESTING
value|64
end_define

begin_decl_stmt
name|pPointer
name|PorFHeader
index|[
name|MAXNESTING
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|short
name|nesting
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*      *	pointer to namelist entry of record in progress      *	see RecTCopy, FieldCopy and VarntCopy      */
end_comment

begin_decl_stmt
name|struct
name|nl
modifier|*
name|inrecord
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*      *	functions which are of type other than int      */
end_comment

begin_function_decl
name|struct
name|nl
modifier|*
name|nllook
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|nl
modifier|*
name|nllook1
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|nl
modifier|*
name|chainlookup
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|pPointer
name|PorFCopy
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|pPointer
name|FileCopy
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|pPointer
name|ParamCopy
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|pPointer
name|LabelDCopy
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|pPointer
name|ConstDecl
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|pPointer
name|TypeDecl
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|pPointer
name|FieldCopy
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|pPointer
name|VarntCopy
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|pPointer
name|EnumTCopy
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|pPointer
name|VarDecl
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|pPointer
name|ThreadSymbol
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|pPointer
name|ThreadName
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|pPointer
name|UnOpCopy
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|pPointer
name|PtrTCopy
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|pPointer
name|PackTCopy
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|pPointer
name|RangeTCopy
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|pPointer
name|ArrayTCopy
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|pPointer
name|FileTCopy
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|pPointer
name|SetTCopy
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|pPointer
name|RecTCopy
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|pPointer
name|VCaseCopy
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|pPointer
name|CasedCopy
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|pPointer
name|LabelCopy
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|pPointer
name|PCallCopy
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|pPointer
name|CaseSCopy
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|pPointer
name|WithCopy
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|pPointer
name|WhileCopy
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|pPointer
name|RepeatCopy
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|pPointer
name|ForCopy
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|pPointer
name|ForDCopy
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|pPointer
name|GotoCopy
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|pPointer
name|IfCopy
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|pPointer
name|AssertCopy
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|pPointer
name|AssignCopy
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|pPointer
name|BinOpCopy
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|pPointer
name|NilCopy
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|pPointer
name|FCallCopy
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|pPointer
name|SetCopy
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|pPointer
name|RangeCopy
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|pPointer
name|VarCopy
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|pPointer
name|SubscCopy
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|pPointer
name|SelCopy
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|pPointer
name|PtrCopy
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|pPointer
name|WidthCopy
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|pPointer
name|tCopy
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|pPointer
name|ListCopy
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|pPointer
name|ListAppend
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|pPointer
name|iCopy
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|pPointer
name|fCopy
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|pPointer
name|sCopy
parameter_list|()
function_decl|;
end_function_decl

end_unit

