begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $XConsortium: Atoms.h,v 1.8 91/07/23 14:39:51 converse Exp $  *  * Copyright 1988 by the Massachusetts Institute of Technology  *  * Permission to use, copy, modify, and distribute this software and its  * documentation for any purpose and without fee is hereby granted, provided   * that the above copyright notice appear in all copies and that both that   * copyright notice and this permission notice appear in supporting   * documentation, and that the name of M.I.T. not be used in advertising  * or publicity pertaining to distribution of the software without specific,   * written prior permission. M.I.T. makes no representations about the   * suitability of this software for any purpose.  It is provided "as is"  * without express or implied warranty.  *  * The X Window System is a Trademark of MIT.  *  * The interfaces described by this header file are for miscellaneous utilities  * and are not part of the Xlib standard.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_XMU_ATOMS_H_
end_ifndef

begin_define
define|#
directive|define
name|_XMU_ATOMS_H_
end_define

begin_include
include|#
directive|include
file|<X11/Intrinsic.h>
end_include

begin_include
include|#
directive|include
file|<X11/Xfuncproto.h>
end_include

begin_typedef
typedef|typedef
name|struct
name|_AtomRec
modifier|*
name|AtomPtr
typedef|;
end_typedef

begin_decl_stmt
specifier|extern
name|AtomPtr
name|_XA_ATOM_PAIR
decl_stmt|,
name|_XA_CHARACTER_POSITION
decl_stmt|,
name|_XA_CLASS
decl_stmt|,
name|_XA_CLIENT_WINDOW
decl_stmt|,
name|_XA_CLIPBOARD
decl_stmt|,
name|_XA_COMPOUND_TEXT
decl_stmt|,
name|_XA_DECNET_ADDRESS
decl_stmt|,
name|_XA_DELETE
decl_stmt|,
name|_XA_FILENAME
decl_stmt|,
name|_XA_HOSTNAME
decl_stmt|,
name|_XA_IP_ADDRESS
decl_stmt|,
name|_XA_LENGTH
decl_stmt|,
name|_XA_LIST_LENGTH
decl_stmt|,
name|_XA_NAME
decl_stmt|,
name|_XA_NET_ADDRESS
decl_stmt|,
name|_XA_NULL
decl_stmt|,
name|_XA_OWNER_OS
decl_stmt|,
name|_XA_SPAN
decl_stmt|,
name|_XA_TARGETS
decl_stmt|,
name|_XA_TEXT
decl_stmt|,
name|_XA_TIMESTAMP
decl_stmt|,
name|_XA_USER
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|XA_ATOM_PAIR
parameter_list|(
name|d
parameter_list|)
value|XmuInternAtom(d, _XA_ATOM_PAIR)
end_define

begin_define
define|#
directive|define
name|XA_CHARACTER_POSITION
parameter_list|(
name|d
parameter_list|)
value|XmuInternAtom(d, _XA_CHARACTER_POSITION)
end_define

begin_define
define|#
directive|define
name|XA_CLASS
parameter_list|(
name|d
parameter_list|)
value|XmuInternAtom(d, _XA_CLASS)
end_define

begin_define
define|#
directive|define
name|XA_CLIENT_WINDOW
parameter_list|(
name|d
parameter_list|)
value|XmuInternAtom(d, _XA_CLIENT_WINDOW)
end_define

begin_define
define|#
directive|define
name|XA_CLIPBOARD
parameter_list|(
name|d
parameter_list|)
value|XmuInternAtom(d, _XA_CLIPBOARD)
end_define

begin_define
define|#
directive|define
name|XA_COMPOUND_TEXT
parameter_list|(
name|d
parameter_list|)
value|XmuInternAtom(d, _XA_COMPOUND_TEXT)
end_define

begin_define
define|#
directive|define
name|XA_DECNET_ADDRESS
parameter_list|(
name|d
parameter_list|)
value|XmuInternAtom(d, _XA_DECNET_ADDRESS)
end_define

begin_define
define|#
directive|define
name|XA_DELETE
parameter_list|(
name|d
parameter_list|)
value|XmuInternAtom(d, _XA_DELETE)
end_define

begin_define
define|#
directive|define
name|XA_FILENAME
parameter_list|(
name|d
parameter_list|)
value|XmuInternAtom(d, _XA_FILENAME)
end_define

begin_define
define|#
directive|define
name|XA_HOSTNAME
parameter_list|(
name|d
parameter_list|)
value|XmuInternAtom(d, _XA_HOSTNAME)
end_define

begin_define
define|#
directive|define
name|XA_IP_ADDRESS
parameter_list|(
name|d
parameter_list|)
value|XmuInternAtom(d, _XA_IP_ADDRESS)
end_define

begin_define
define|#
directive|define
name|XA_LENGTH
parameter_list|(
name|d
parameter_list|)
value|XmuInternAtom(d, _XA_LENGTH)
end_define

begin_define
define|#
directive|define
name|XA_LIST_LENGTH
parameter_list|(
name|d
parameter_list|)
value|XmuInternAtom(d, _XA_LIST_LENGTH)
end_define

begin_define
define|#
directive|define
name|XA_NAME
parameter_list|(
name|d
parameter_list|)
value|XmuInternAtom(d, _XA_NAME)
end_define

begin_define
define|#
directive|define
name|XA_NET_ADDRESS
parameter_list|(
name|d
parameter_list|)
value|XmuInternAtom(d, _XA_NET_ADDRESS)
end_define

begin_define
define|#
directive|define
name|XA_NULL
parameter_list|(
name|d
parameter_list|)
value|XmuInternAtom(d, _XA_NULL)
end_define

begin_define
define|#
directive|define
name|XA_OWNER_OS
parameter_list|(
name|d
parameter_list|)
value|XmuInternAtom(d, _XA_OWNER_OS)
end_define

begin_define
define|#
directive|define
name|XA_SPAN
parameter_list|(
name|d
parameter_list|)
value|XmuInternAtom(d, _XA_SPAN)
end_define

begin_define
define|#
directive|define
name|XA_TARGETS
parameter_list|(
name|d
parameter_list|)
value|XmuInternAtom(d, _XA_TARGETS)
end_define

begin_define
define|#
directive|define
name|XA_TEXT
parameter_list|(
name|d
parameter_list|)
value|XmuInternAtom(d, _XA_TEXT)
end_define

begin_define
define|#
directive|define
name|XA_TIMESTAMP
parameter_list|(
name|d
parameter_list|)
value|XmuInternAtom(d, _XA_TIMESTAMP)
end_define

begin_define
define|#
directive|define
name|XA_USER
parameter_list|(
name|d
parameter_list|)
value|XmuInternAtom(d, _XA_USER)
end_define

begin_function_decl
name|_XFUNCPROTOBEGIN
specifier|extern
name|char
modifier|*
name|XmuGetAtomName
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Display
modifier|*
comment|/* dpy */
parameter_list|,
name|Atom
comment|/* atom */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|Atom
name|XmuInternAtom
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Display
modifier|*
comment|/* dpy */
parameter_list|,
name|AtomPtr
comment|/* atom_ptr */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|XmuInternStrings
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Display
modifier|*
comment|/* dpy */
parameter_list|,
name|String
modifier|*
comment|/* names */
parameter_list|,
name|Cardinal
comment|/* count */
parameter_list|,
name|Atom
modifier|*
comment|/* atoms_return */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|AtomPtr
name|XmuMakeAtom
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|_Xconst
name|char
modifier|*
comment|/* name	*/
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|char
modifier|*
name|XmuNameOfAtom
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|AtomPtr
comment|/* atom_ptr */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_macro
name|_XFUNCPROTOEND
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _XMU_ATOMS_H_ */
end_comment

end_unit

