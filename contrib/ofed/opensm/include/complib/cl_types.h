begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2004-2009 Voltaire, Inc. All rights reserved.  * Copyright (c) 2002-2010 Mellanox Technologies LTD. All rights reserved.  * Copyright (c) 1996-2003 Intel Corporation. All rights reserved.  *  * This software is available to you under a choice of one of two  * licenses.  You may choose to be licensed under the terms of the GNU  * General Public License (GPL) Version 2, available from the file  * COPYING in the main directory of this source tree, or the  * OpenIB.org BSD license below:  *  *     Redistribution and use in source and binary forms, with or  *     without modification, are permitted provided that the following  *     conditions are met:  *  *      - Redistributions of source code must retain the above  *        copyright notice, this list of conditions and the following  *        disclaimer.  *  *      - Redistributions in binary form must reproduce the above  *        copyright notice, this list of conditions and the following  *        disclaimer in the documentation and/or other materials  *        provided with the distribution.  *  * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,  * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF  * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND  * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS  * BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN  * ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN  * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE  * SOFTWARE.  *  */
end_comment

begin_comment
comment|/*  * Abstract:  *	Defines standard return codes, keywords, macros, and debug levels.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__WIN__
end_ifdef

begin_pragma
pragma|#
directive|pragma
name|warning
name|(
name|disable
name|:
name|4996
name|)
end_pragma

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|_CL_TYPES_H_
end_ifndef

begin_define
define|#
directive|define
name|_CL_TYPES_H_
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|__cplusplus
end_ifdef

begin_define
define|#
directive|define
name|BEGIN_C_DECLS
value|extern "C" {
end_define

begin_define
define|#
directive|define
name|END_C_DECLS
value|}
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* !__cplusplus */
end_comment

begin_define
define|#
directive|define
name|BEGIN_C_DECLS
end_define

begin_define
define|#
directive|define
name|END_C_DECLS
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __cplusplus */
end_comment

begin_macro
name|BEGIN_C_DECLS
end_macro

begin_include
include|#
directive|include
file|<complib/cl_types_osd.h>
end_include

begin_include
include|#
directive|include
file|<stddef.h>
end_include

begin_typedef
typedef|typedef
name|uint16_t
name|net16_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|uint32_t
name|net32_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|uint64_t
name|net64_t
typedef|;
end_typedef

begin_comment
comment|/* explicit cast of void* to uint32_t */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|ASSERT_VOIDP2UINTN
end_ifndef

begin_if
if|#
directive|if
name|__WORDSIZE
operator|==
literal|64
end_if

begin_define
define|#
directive|define
name|ASSERT_VOIDP2UINTN
parameter_list|(
name|var
parameter_list|)
define|\
value|CL_ASSERT( (intptr_t)var<= 0xffffffffffffffffL )
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/*  __WORDSIZE == 64 */
end_comment

begin_if
if|#
directive|if
name|__WORDSIZE
operator|==
literal|32
end_if

begin_comment
comment|/* need to cast carefully to avoid the warining of un-needed check */
end_comment

begin_define
define|#
directive|define
name|ASSERT_VOIDP2UINTN
parameter_list|(
name|var
parameter_list|)
define|\
value|CL_ASSERT( (intptr_t)var<= 0x100000000ULL )
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/*  __WORDSIZE == 32 */
end_comment

begin_error
error|#
directive|error
literal|"Need to know WORDSIZE to tell how to cast to unsigned long int"
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  __WORDSIZE == 32 */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  __WORDSIZE == 64 */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* explicit casting of void* to long */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|CAST_P2LONG
end_ifndef

begin_define
define|#
directive|define
name|CAST_P2LONG
parameter_list|(
name|var
parameter_list|)
value|((intptr_t)(var))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/****d* Component Library: Pointer Manipulation/offsetof * NAME *	offsetof * * DESCRIPTION *	The offsetof macro returns the offset of a member within a structure. * * SYNOPSIS *	uintptr_t *	offsetof( *		IN TYPE, *		IN MEMBER ); * * PARAMETERS *	TYPE *		[in] Name of the structure containing the specified member. * *	MEMBER *		[in] Name of the member whose offset in the specified structure *		is to be returned. * * RETURN VALUE *	Number of bytes from the beginning of the structure to the *	specified member. * * SEE ALSO *	PARENT_STRUCT *********/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|offsetof
end_ifndef

begin_define
define|#
directive|define
name|offsetof
parameter_list|(
name|TYPE
parameter_list|,
name|MEMBER
parameter_list|)
value|((uintptr_t)&((TYPE *)0)->MEMBER)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/****d* Component Library: Pointer Manipulation/PARENT_STRUCT * NAME *	PARENT_STRUCT * * DESCRIPTION *	The PARENT_STRUCT macro returns a pointer to a structure *	given a name and pointer to one of its members. * * SYNOPSIS *	PARENT_TYPE* *	PARENT_STRUCT( *		IN void* const p_member, *		IN PARENT_TYPE, *		IN MEMBER_NAME ); * * PARAMETERS *	p_member *		[in] Pointer to the MEMBER_NAME member of a PARENT_TYPE structure. * *	PARENT_TYPE *		[in] Name of the structure containing the specified member. * *	MEMBER_NAME *		[in] Name of the member whose address is passed in the p_member *		parameter. * * RETURN VALUE *	Pointer to a structure of type PARENT_TYPE whose MEMBER_NAME member is *	located at p_member. * * SEE ALSO *	offsetof *********/
end_comment

begin_define
define|#
directive|define
name|PARENT_STRUCT
parameter_list|(
name|p_member
parameter_list|,
name|PARENT_TYPE
parameter_list|,
name|MEMBER_NAME
parameter_list|)
define|\
value|((PARENT_TYPE*)((uint8_t*)(p_member) - offsetof(PARENT_TYPE, MEMBER_NAME)))
end_define

begin_comment
comment|/****d* Component Library/Parameter Keywords * NAME *	Parameter Keywords * * DESCRIPTION *	The Parameter Keywords can be used to clarify the usage of function *	parameters to users. * * VALUES *	IN *		Designates that the parameter is used as input to a function. * *	OUT *		Designates that the parameter's value will be set by the function. * *	OPTIONAL *		Designates that the parameter is optional, and may be NULL. *		The OPTIONAL keyword, if used, follows the parameter name. * * EXAMPLE *	// Function declaration. *	void* *	my_func( *	    IN void* const p_param1, *	    OUT void** const p_handle OPTIONAL ); * * NOTES *	Multiple keywords can apply to a single parameter. The IN and OUT *	keywords precede the parameter type. The OPTIONAL *	keyword, if used, follows the parameter name. *********/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|IN
end_ifndef

begin_define
define|#
directive|define
name|IN
end_define

begin_comment
comment|/* Function input parameter */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|OUT
end_ifndef

begin_define
define|#
directive|define
name|OUT
end_define

begin_comment
comment|/* Function output parameter */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|OPTIONAL
end_ifndef

begin_define
define|#
directive|define
name|OPTIONAL
end_define

begin_comment
comment|/* Optional function parameter - NULL if not used */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% %%                  Function Returns And Completion Codes					 %% %%																			 %% %% The text for any addition to this enumerated type must be added to the	 %% %% string array defined in<cl_statustext.c>.								 %% %%																			 %% %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%*/
end_comment

begin_comment
comment|/****d* Component Library/Data Types * NAME *	Data Types * * DESCRIPTION *	The component library provides and uses explicitly sized types. * * VALUES *	char *		8-bit, defined by compiler. * *	void *		0-bit, defined by compiler. * *	int8_t *		8-bit signed integer. * *	uint8_t *		8-bit unsigned integer. * *	int16_t *		16-bit signed integer. * *	uint16_t *		16-bit unsigned integer. * *	net16_t *		16-bit network byte order value. * *	int32_t *		32-bit signed integer. * *	uint32_t *		32-bit unsigned integer. * *	net32_t *		32-bit network byte order value. * *	int64_t *		64-bit signed integer. * *	uint64_t *		64-bit unsigned integer. * *	net64_t *		64-bit network byte order value. * *	boolean_t *		integral sized.  Set to TRUE or FALSE and used in logical expressions. * * NOTES *	Pointer types are not defined as these provide no value and can potentially *	lead to naming confusion. *********/
end_comment

begin_comment
comment|/****d* Component Library: Data Types/cl_status_t * NAME *	cl_status_t * * DESCRIPTION *	The cl_status_t return types are used by the component library to *	provide detailed function return values. * * SYNOPSIS */
end_comment

begin_define
define|#
directive|define
name|CL_SUCCESS
value|0
end_define

begin_define
define|#
directive|define
name|CL_ERROR
value|1
end_define

begin_define
define|#
directive|define
name|CL_INVALID_STATE
value|2
end_define

begin_define
define|#
directive|define
name|CL_INVALID_OPERATION
value|3
end_define

begin_define
define|#
directive|define
name|CL_INVALID_SETTING
value|4
end_define

begin_define
define|#
directive|define
name|CL_INVALID_PARAMETER
value|5
end_define

begin_define
define|#
directive|define
name|CL_INSUFFICIENT_RESOURCES
value|6
end_define

begin_define
define|#
directive|define
name|CL_INSUFFICIENT_MEMORY
value|7
end_define

begin_define
define|#
directive|define
name|CL_INVALID_PERMISSION
value|8
end_define

begin_define
define|#
directive|define
name|CL_COMPLETED
value|9
end_define

begin_define
define|#
directive|define
name|CL_NOT_DONE
value|10
end_define

begin_define
define|#
directive|define
name|CL_PENDING
value|11
end_define

begin_define
define|#
directive|define
name|CL_TIMEOUT
value|12
end_define

begin_define
define|#
directive|define
name|CL_CANCELED
value|13
end_define

begin_define
define|#
directive|define
name|CL_REJECT
value|14
end_define

begin_define
define|#
directive|define
name|CL_OVERRUN
value|15
end_define

begin_define
define|#
directive|define
name|CL_NOT_FOUND
value|16
end_define

begin_define
define|#
directive|define
name|CL_UNAVAILABLE
value|17
end_define

begin_define
define|#
directive|define
name|CL_BUSY
value|18
end_define

begin_define
define|#
directive|define
name|CL_DISCONNECT
value|19
end_define

begin_define
define|#
directive|define
name|CL_DUPLICATE
value|20
end_define

begin_define
define|#
directive|define
name|CL_STATUS_COUNT
value|21
end_define

begin_comment
comment|/* should be the last value */
end_comment

begin_typedef
typedef|typedef
name|int
name|cl_status_t
typedef|;
end_typedef

begin_comment
comment|/* * SEE ALSO *	Data Types, CL_STATUS_MSG *********/
end_comment

begin_comment
comment|/* Status values above converted to text for easier printing. */
end_comment

begin_decl_stmt
specifier|extern
specifier|const
name|char
modifier|*
name|cl_status_text
index|[]
decl_stmt|;
end_decl_stmt

begin_ifndef
ifndef|#
directive|ifndef
name|cl_panic
end_ifndef

begin_comment
comment|/****f* Component Library: Error Trapping/cl_panic * NAME *	cl_panic * * DESCRIPTION *	Halts execution of the current process.  Halts the system if called in *	from the kernel. * * SYNOPSIS */
end_comment

begin_function_decl
name|void
name|cl_panic
parameter_list|(
name|IN
specifier|const
name|char
modifier|*
specifier|const
name|message
parameter_list|,
name|IN
modifier|...
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* * PARAMETERS *	message *		[in] ANSI string formatted identically as for a call to the standard C *		function printf describing the cause for the panic. * *	... *		[in] Extra parameters for string formatting, as defined for the *		standard C function printf. * * RETURN VALUE *	This function does not return. * * NOTES *	The formatting of the message string is the same as for printf * *	cl_panic sends the message to the current message logging target. *********/
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* cl_panic */
end_comment

begin_comment
comment|/****d* Component Library: Data Types/CL_STATUS_MSG * NAME *	CL_STATUS_MSG * * DESCRIPTION *	The CL_STATUS_MSG macro returns a textual representation of *	an cl_status_t code. * * SYNOPSIS *	const char* *	CL_STATUS_MSG( *		IN cl_status_t errcode ); * * PARAMETERS *	errcode *		[in] cl_status_t code for which to return a text representation. * * RETURN VALUE *	Pointer to a string containing a textual representation of the errcode *	parameter. * * NOTES *	This function performs boundary checking on the cl_status_t value, *	masking off the upper 24-bits. If the value is out of bounds, the string *	"invalid status code" is returned. * * SEE ALSO *	cl_status_t *********/
end_comment

begin_define
define|#
directive|define
name|CL_STATUS_MSG
parameter_list|(
name|errcode
parameter_list|)
define|\
value|((errcode< CL_STATUS_COUNT)?cl_status_text[errcode]:"invalid status code")
end_define

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|FALSE
argument_list|)
end_if

begin_define
define|#
directive|define
name|FALSE
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !defined( FALSE ) */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|TRUE
argument_list|)
end_if

begin_define
define|#
directive|define
name|TRUE
value|(!FALSE)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !defined( TRUE ) */
end_comment

begin_comment
comment|/****d* Component Library: Unreferenced Parameters/UNUSED_PARAM * NAME *	UNUSED_PARAM * * DESCRIPTION *	The UNUSED_PARAM macro can be used to eliminates compiler warnings related *	to intentionally unused formal parameters in function implementations. * * SYNOPSIS *	UNUSED_PARAM( P ) * * EXAMPLE *	void my_func( int32_t value ) *	{ *		UNUSED_PARAM( value ); *	} *********/
end_comment

begin_comment
comment|/****d* Component Library/Object States * NAME *	Object States * * DESCRIPTION *	The object states enumerated type defines the valid states of components. * * SYNOPSIS */
end_comment

begin_typedef
typedef|typedef
enum|enum
name|_cl_state
block|{
name|CL_UNINITIALIZED
init|=
literal|1
block|,
name|CL_INITIALIZED
block|,
name|CL_DESTROYING
block|,
name|CL_DESTROYED
block|}
name|cl_state_t
typedef|;
end_typedef

begin_comment
comment|/* * VALUES *	CL_UNINITIALIZED *		Indicates that initialization was not invoked successfully. * *	CL_INITIALIZED *		Indicates initialization was successful. * *	CL_DESTROYING *		Indicates that the object is undergoing destruction. * *	CL_DESTROYED *		Indicates that the object's destructor has already been called.  Most *		objects set their final state to CL_DESTROYED before freeing the *		memory associated with the object. *********/
end_comment

begin_comment
comment|/****d* Component Library: Object States/cl_is_state_valid * NAME *	cl_is_state_valid * * DESCRIPTION *	The cl_is_state_valid function returns whether a state has a valid value. * * SYNOPSIS */
end_comment

begin_function
specifier|static
specifier|inline
name|boolean_t
name|cl_is_state_valid
parameter_list|(
name|IN
specifier|const
name|cl_state_t
name|state
parameter_list|)
block|{
return|return
operator|(
operator|(
name|state
operator|==
name|CL_UNINITIALIZED
operator|)
operator|||
operator|(
name|state
operator|==
name|CL_INITIALIZED
operator|)
operator|||
operator|(
name|state
operator|==
name|CL_DESTROYING
operator|)
operator|||
operator|(
name|state
operator|==
name|CL_DESTROYED
operator|)
operator|)
return|;
block|}
end_function

begin_comment
comment|/* * PARAMETERS *	state *		State whose value to validate. * * RETURN VALUES *	TRUE if the specified state has a valid value. * *	FALSE otherwise. * * NOTES *	This function is used in debug builds to check for valid states.  If an *	uninitialized object is passed, the memory for the state may cause the *	state to have an invalid value. * * SEE ALSO *	Object States *********/
end_comment

begin_macro
name|END_C_DECLS
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _DATA_TYPES_H_ */
end_comment

end_unit

