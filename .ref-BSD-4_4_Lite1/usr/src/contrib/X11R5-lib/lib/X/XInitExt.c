begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $XConsortium: XInitExt.c,v 11.28 91/01/08 14:41:05 gildea Exp $ */
end_comment

begin_comment
comment|/* Copyright  Massachusetts Institute of Technology 1987 */
end_comment

begin_comment
comment|/* Permission to use, copy, modify, distribute, and sell this software and its documentation for any purpose is hereby granted without fee, provided that the above copyright notice appear in all copies and that both that copyright notice and this permission notice appear in supporting documentation, and that the name of M.I.T. not be used in advertising or publicity pertaining to distribution of the software without specific, written prior permission.  M.I.T. makes no representations about the suitability of this software for any purpose.  It is provided "as is" without express or implied warranty. */
end_comment

begin_include
include|#
directive|include
file|<X11/Xlibint.h>
end_include

begin_include
include|#
directive|include
file|<X11/Xos.h>
end_include

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_function_decl
specifier|extern
name|Bool
name|_XUnknownWireEvent
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|Status
name|_XUnknownNativeEvent
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|Bool
name|_XDefaultWireError
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/*  * This routine is used to link a extension in so it will be called  * at appropriate times.  */
end_comment

begin_if
if|#
directive|if
name|NeedFunctionPrototypes
end_if

begin_function
name|XExtCodes
modifier|*
name|XInitExtension
parameter_list|(
name|Display
modifier|*
name|dpy
parameter_list|,
name|_Xconst
name|char
modifier|*
name|name
parameter_list|)
else|#
directive|else
function|XExtCodes *XInitExtension
parameter_list|(
name|dpy
parameter_list|,
name|name
parameter_list|)
name|Display
modifier|*
name|dpy
decl_stmt|;
name|char
modifier|*
name|name
decl_stmt|;
endif|#
directive|endif
block|{
name|XExtCodes
name|codes
decl_stmt|;
comment|/* temp. place for extension information. */
specifier|register
name|_XExtension
modifier|*
name|ext
decl_stmt|;
comment|/* need a place to build it all */
if|if
condition|(
operator|!
name|XQueryExtension
argument_list|(
name|dpy
argument_list|,
name|name
argument_list|,
operator|&
name|codes
operator|.
name|major_opcode
argument_list|,
operator|&
name|codes
operator|.
name|first_event
argument_list|,
operator|&
name|codes
operator|.
name|first_error
argument_list|)
condition|)
return|return
operator|(
name|NULL
operator|)
return|;
name|LockDisplay
argument_list|(
name|dpy
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
operator|(
name|ext
operator|=
operator|(
name|_XExtension
operator|*
operator|)
name|Xcalloc
argument_list|(
literal|1
argument_list|,
sizeof|sizeof
argument_list|(
name|_XExtension
argument_list|)
argument_list|)
operator|)
operator|||
operator|!
operator|(
name|ext
operator|->
name|name
operator|=
name|Xmalloc
argument_list|(
operator|(
name|unsigned
operator|)
name|strlen
argument_list|(
name|name
argument_list|)
operator|+
literal|1
argument_list|)
operator|)
condition|)
block|{
if|if
condition|(
name|ext
condition|)
name|Xfree
argument_list|(
operator|(
name|char
operator|*
operator|)
name|ext
argument_list|)
expr_stmt|;
name|UnlockDisplay
argument_list|(
name|dpy
argument_list|)
expr_stmt|;
return|return
operator|(
name|XExtCodes
operator|*
operator|)
name|NULL
return|;
block|}
name|codes
operator|.
name|extension
operator|=
name|dpy
operator|->
name|ext_number
operator|++
expr_stmt|;
name|ext
operator|->
name|codes
operator|=
name|codes
expr_stmt|;
operator|(
name|void
operator|)
name|strcpy
argument_list|(
name|ext
operator|->
name|name
argument_list|,
name|name
argument_list|)
expr_stmt|;
comment|/* chain it onto the display list */
name|ext
operator|->
name|next
operator|=
name|dpy
operator|->
name|ext_procs
expr_stmt|;
name|dpy
operator|->
name|ext_procs
operator|=
name|ext
expr_stmt|;
name|UnlockDisplay
argument_list|(
name|dpy
argument_list|)
expr_stmt|;
return|return
operator|(
operator|&
name|ext
operator|->
name|codes
operator|)
return|;
comment|/* tell him which extension */
block|}
end_function

begin_function
name|XExtCodes
modifier|*
name|XAddExtension
parameter_list|(
name|dpy
parameter_list|)
name|Display
modifier|*
name|dpy
decl_stmt|;
block|{
specifier|register
name|_XExtension
modifier|*
name|ext
decl_stmt|;
name|LockDisplay
argument_list|(
name|dpy
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
operator|(
name|ext
operator|=
operator|(
name|_XExtension
operator|*
operator|)
name|Xcalloc
argument_list|(
literal|1
argument_list|,
sizeof|sizeof
argument_list|(
name|_XExtension
argument_list|)
argument_list|)
operator|)
condition|)
block|{
name|UnlockDisplay
argument_list|(
name|dpy
argument_list|)
expr_stmt|;
return|return
operator|(
name|XExtCodes
operator|*
operator|)
name|NULL
return|;
block|}
name|ext
operator|->
name|codes
operator|.
name|extension
operator|=
name|dpy
operator|->
name|ext_number
operator|++
expr_stmt|;
comment|/* chain it onto the display list */
name|ext
operator|->
name|next
operator|=
name|dpy
operator|->
name|ext_procs
expr_stmt|;
name|dpy
operator|->
name|ext_procs
operator|=
name|ext
expr_stmt|;
name|UnlockDisplay
argument_list|(
name|dpy
argument_list|)
expr_stmt|;
return|return
operator|(
operator|&
name|ext
operator|->
name|codes
operator|)
return|;
comment|/* tell him which extension */
block|}
end_function

begin_function
specifier|static
name|_XExtension
modifier|*
name|XLookupExtension
parameter_list|(
name|dpy
parameter_list|,
name|extension
parameter_list|)
specifier|register
name|Display
modifier|*
name|dpy
decl_stmt|;
comment|/* display */
specifier|register
name|int
name|extension
decl_stmt|;
comment|/* extension number */
block|{
specifier|register
name|_XExtension
modifier|*
name|ext
init|=
name|dpy
operator|->
name|ext_procs
decl_stmt|;
while|while
condition|(
name|ext
operator|!=
name|NULL
condition|)
block|{
if|if
condition|(
name|ext
operator|->
name|codes
operator|.
name|extension
operator|==
name|extension
condition|)
return|return
operator|(
name|ext
operator|)
return|;
name|ext
operator|=
name|ext
operator|->
name|next
expr_stmt|;
block|}
return|return
operator|(
name|NULL
operator|)
return|;
block|}
end_function

begin_function
name|XExtData
modifier|*
modifier|*
name|XEHeadOfExtensionList
parameter_list|(
name|object
parameter_list|)
name|XEDataObject
name|object
decl_stmt|;
block|{
return|return
operator|*
operator|(
name|XExtData
operator|*
operator|*
operator|*
operator|)
operator|&
name|object
return|;
block|}
end_function

begin_macro
name|XAddToExtensionList
argument_list|(
argument|structure
argument_list|,
argument|ext_data
argument_list|)
end_macro

begin_decl_stmt
name|XExtData
modifier|*
modifier|*
name|structure
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|XExtData
modifier|*
name|ext_data
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|ext_data
operator|->
name|next
operator|=
operator|*
name|structure
expr_stmt|;
operator|*
name|structure
operator|=
name|ext_data
expr_stmt|;
block|}
end_block

begin_function
name|XExtData
modifier|*
name|XFindOnExtensionList
parameter_list|(
name|structure
parameter_list|,
name|number
parameter_list|)
name|XExtData
modifier|*
modifier|*
name|structure
decl_stmt|;
name|int
name|number
decl_stmt|;
block|{
name|XExtData
modifier|*
name|ext
decl_stmt|;
name|ext
operator|=
operator|*
name|structure
expr_stmt|;
while|while
condition|(
name|ext
operator|&&
operator|(
name|ext
operator|->
name|number
operator|!=
name|number
operator|)
condition|)
name|ext
operator|=
name|ext
operator|->
name|next
expr_stmt|;
return|return
name|ext
return|;
block|}
end_function

begin_comment
comment|/*  * Routines to hang procs on the extension structure.  */
end_comment

begin_if
if|#
directive|if
name|NeedFunctionPrototypes
end_if

begin_macro
name|int
argument_list|(
argument|*XESetCreateGC(     Display*	dpy,     int		extension,     int (*proc) (
if|#
directive|if
name|NeedNestedPrototypes
argument|Display*
comment|/* display */
argument|, 	      GC
comment|/* gc */
argument|, 	      XExtCodes*
comment|/* codes */
endif|#
directive|endif
argument|)     )
argument_list|)
end_macro

begin_expr_stmt
operator|(
if|#
directive|if
name|NeedNestedPrototypes
name|Display
operator|*
operator|,
name|GC
operator|,
name|XExtCodes
operator|*
endif|#
directive|endif
operator|)
else|#
directive|else
name|int
argument_list|(
argument|*XESetCreateGC(dpy, extension, proc)
argument_list|)
operator|(
operator|)
name|Display
operator|*
name|dpy
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* display */
end_comment

begin_decl_stmt
name|int
name|extension
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* extension number */
end_comment

begin_function_decl
name|int
function_decl|(
modifier|*
name|proc
function_decl|)
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* routine to call when GC created */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_block
block|{
specifier|register
name|_XExtension
modifier|*
name|e
decl_stmt|;
comment|/* for lookup of extension */
specifier|register
name|int
function_decl|(
modifier|*
name|oldproc
function_decl|)
parameter_list|()
function_decl|;
if|if
condition|(
operator|(
name|e
operator|=
name|XLookupExtension
argument_list|(
name|dpy
argument_list|,
name|extension
argument_list|)
operator|)
operator|==
name|NULL
condition|)
return|return
operator|(
name|NULL
operator|)
return|;
name|LockDisplay
argument_list|(
name|dpy
argument_list|)
expr_stmt|;
name|oldproc
operator|=
name|e
operator|->
name|create_GC
expr_stmt|;
name|e
operator|->
name|create_GC
operator|=
name|proc
expr_stmt|;
name|UnlockDisplay
argument_list|(
name|dpy
argument_list|)
expr_stmt|;
return|return
operator|(
name|oldproc
operator|)
return|;
block|}
end_block

begin_if
if|#
directive|if
name|NeedFunctionPrototypes
end_if

begin_macro
name|int
argument_list|(
argument|*XESetCopyGC( 	Display * dpy, 	int extension, 	int (*proc)(
if|#
directive|if
name|NeedNestedPrototypes
argument|Display*
comment|/* display */
argument|,               GC
comment|/* gc */
argument|,               XExtCodes*
comment|/* codes */
endif|#
directive|endif
argument|) )
argument_list|)
end_macro

begin_expr_stmt
operator|(
if|#
directive|if
name|NeedNestedPrototypes
name|Display
operator|*
operator|,
name|GC
operator|,
name|XExtCodes
operator|*
endif|#
directive|endif
operator|)
else|#
directive|else
name|int
argument_list|(
argument|*XESetCopyGC(dpy, extension, proc)
argument_list|)
operator|(
operator|)
name|Display
operator|*
name|dpy
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* display */
end_comment

begin_decl_stmt
name|int
name|extension
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* extension number */
end_comment

begin_function_decl
name|int
function_decl|(
modifier|*
name|proc
function_decl|)
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* routine to call when GC copied */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_block
block|{
specifier|register
name|_XExtension
modifier|*
name|e
decl_stmt|;
comment|/* for lookup of extension */
specifier|register
name|int
function_decl|(
modifier|*
name|oldproc
function_decl|)
parameter_list|()
function_decl|;
if|if
condition|(
operator|(
name|e
operator|=
name|XLookupExtension
argument_list|(
name|dpy
argument_list|,
name|extension
argument_list|)
operator|)
operator|==
name|NULL
condition|)
return|return
operator|(
name|NULL
operator|)
return|;
name|LockDisplay
argument_list|(
name|dpy
argument_list|)
expr_stmt|;
name|oldproc
operator|=
name|e
operator|->
name|copy_GC
expr_stmt|;
name|e
operator|->
name|copy_GC
operator|=
name|proc
expr_stmt|;
name|UnlockDisplay
argument_list|(
name|dpy
argument_list|)
expr_stmt|;
return|return
operator|(
name|oldproc
operator|)
return|;
block|}
end_block

begin_if
if|#
directive|if
name|NeedFunctionPrototypes
end_if

begin_macro
name|int
argument_list|(
argument|*XESetFlushGC(     Display* dpy,     int extension,     int (*proc) (
if|#
directive|if
name|NeedNestedPrototypes
argument|Display*
comment|/* display */
argument|,               GC
comment|/* gc */
argument|,               XExtCodes*
comment|/* codes */
endif|#
directive|endif
argument|) )
argument_list|)
end_macro

begin_expr_stmt
operator|(
if|#
directive|if
name|NeedNestedPrototypes
name|Display
operator|*
operator|,
name|GC
operator|,
name|XExtCodes
operator|*
endif|#
directive|endif
operator|)
else|#
directive|else
name|int
argument_list|(
argument|*XESetFlushGC(dpy, extension, proc)
argument_list|)
operator|(
operator|)
name|Display
operator|*
name|dpy
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* display */
end_comment

begin_decl_stmt
name|int
name|extension
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* extension number */
end_comment

begin_function_decl
name|int
function_decl|(
modifier|*
name|proc
function_decl|)
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* routine to call when GC copied */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_block
block|{
specifier|register
name|_XExtension
modifier|*
name|e
decl_stmt|;
comment|/* for lookup of extension */
specifier|register
name|int
function_decl|(
modifier|*
name|oldproc
function_decl|)
parameter_list|()
function_decl|;
if|if
condition|(
operator|(
name|e
operator|=
name|XLookupExtension
argument_list|(
name|dpy
argument_list|,
name|extension
argument_list|)
operator|)
operator|==
name|NULL
condition|)
return|return
operator|(
name|NULL
operator|)
return|;
name|LockDisplay
argument_list|(
name|dpy
argument_list|)
expr_stmt|;
name|oldproc
operator|=
name|e
operator|->
name|flush_GC
expr_stmt|;
name|e
operator|->
name|flush_GC
operator|=
name|proc
expr_stmt|;
name|UnlockDisplay
argument_list|(
name|dpy
argument_list|)
expr_stmt|;
return|return
operator|(
name|oldproc
operator|)
return|;
block|}
end_block

begin_if
if|#
directive|if
name|NeedFunctionPrototypes
end_if

begin_macro
name|int
argument_list|(
argument|*XESetFreeGC(     Display* dpy,     int extension,     int (*proc) (
if|#
directive|if
name|NeedNestedPrototypes
argument|Display*
comment|/* display */
argument|,               GC
comment|/* gc */
argument|,               XExtCodes*
comment|/* codes */
endif|#
directive|endif
argument|) )
argument_list|)
end_macro

begin_expr_stmt
operator|(
if|#
directive|if
name|NeedNestedPrototypes
name|Display
operator|*
operator|,
name|GC
operator|,
name|XExtCodes
operator|*
endif|#
directive|endif
operator|)
else|#
directive|else
name|int
argument_list|(
argument|*XESetFreeGC(dpy, extension, proc)
argument_list|)
operator|(
operator|)
name|Display
operator|*
name|dpy
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* display */
end_comment

begin_decl_stmt
name|int
name|extension
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* extension number */
end_comment

begin_function_decl
name|int
function_decl|(
modifier|*
name|proc
function_decl|)
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* routine to call when GC freed */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_block
block|{
specifier|register
name|_XExtension
modifier|*
name|e
decl_stmt|;
comment|/* for lookup of extension */
specifier|register
name|int
function_decl|(
modifier|*
name|oldproc
function_decl|)
parameter_list|()
function_decl|;
if|if
condition|(
operator|(
name|e
operator|=
name|XLookupExtension
argument_list|(
name|dpy
argument_list|,
name|extension
argument_list|)
operator|)
operator|==
name|NULL
condition|)
return|return
operator|(
name|NULL
operator|)
return|;
name|LockDisplay
argument_list|(
name|dpy
argument_list|)
expr_stmt|;
name|oldproc
operator|=
name|e
operator|->
name|free_GC
expr_stmt|;
name|e
operator|->
name|free_GC
operator|=
name|proc
expr_stmt|;
name|UnlockDisplay
argument_list|(
name|dpy
argument_list|)
expr_stmt|;
return|return
operator|(
name|oldproc
operator|)
return|;
block|}
end_block

begin_if
if|#
directive|if
name|NeedFunctionPrototypes
end_if

begin_macro
name|int
argument_list|(
argument|*XESetCreateFont(     Display* dpy,     int extension,     int (*proc) (
if|#
directive|if
name|NeedNestedPrototypes
argument|Display*
comment|/* display */
argument|,               XFontStruct*
comment|/* fs */
argument|,               XExtCodes*
comment|/* codes */
endif|#
directive|endif
argument|) )
argument_list|)
end_macro

begin_expr_stmt
operator|(
if|#
directive|if
name|NeedNestedPrototypes
name|Display
operator|*
operator|,
name|XFontStruct
operator|*
operator|,
name|XExtCodes
operator|*
endif|#
directive|endif
operator|)
else|#
directive|else
name|int
argument_list|(
argument|*XESetCreateFont(dpy, extension, proc)
argument_list|)
operator|(
operator|)
name|Display
operator|*
name|dpy
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* display */
end_comment

begin_decl_stmt
name|int
name|extension
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* extension number */
end_comment

begin_function_decl
name|int
function_decl|(
modifier|*
name|proc
function_decl|)
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* routine to call when font created */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_block
block|{
specifier|register
name|_XExtension
modifier|*
name|e
decl_stmt|;
comment|/* for lookup of extension */
specifier|register
name|int
function_decl|(
modifier|*
name|oldproc
function_decl|)
parameter_list|()
function_decl|;
if|if
condition|(
operator|(
name|e
operator|=
name|XLookupExtension
argument_list|(
name|dpy
argument_list|,
name|extension
argument_list|)
operator|)
operator|==
name|NULL
condition|)
return|return
operator|(
name|NULL
operator|)
return|;
name|LockDisplay
argument_list|(
name|dpy
argument_list|)
expr_stmt|;
name|oldproc
operator|=
name|e
operator|->
name|create_Font
expr_stmt|;
name|e
operator|->
name|create_Font
operator|=
name|proc
expr_stmt|;
name|UnlockDisplay
argument_list|(
name|dpy
argument_list|)
expr_stmt|;
return|return
operator|(
name|oldproc
operator|)
return|;
block|}
end_block

begin_if
if|#
directive|if
name|NeedFunctionPrototypes
end_if

begin_macro
name|int
argument_list|(
argument|*XESetFreeFont(     Display* dpy,     int	extension,     int (*proc) (
if|#
directive|if
name|NeedNestedPrototypes
argument|Display*
comment|/* display */
argument|,               XFontStruct*
comment|/* fs */
argument|,               XExtCodes*
comment|/* codes */
endif|#
directive|endif
argument|) )
argument_list|)
end_macro

begin_expr_stmt
operator|(
if|#
directive|if
name|NeedNestedPrototypes
name|Display
operator|*
operator|,
name|XFontStruct
operator|*
operator|,
name|XExtCodes
operator|*
endif|#
directive|endif
operator|)
else|#
directive|else
name|int
argument_list|(
argument|*XESetFreeFont(dpy, extension, proc)
argument_list|)
operator|(
operator|)
name|Display
operator|*
name|dpy
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* display */
end_comment

begin_decl_stmt
name|int
name|extension
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* extension number */
end_comment

begin_function_decl
name|int
function_decl|(
modifier|*
name|proc
function_decl|)
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* routine to call when font freed */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_block
block|{
specifier|register
name|_XExtension
modifier|*
name|e
decl_stmt|;
comment|/* for lookup of extension */
specifier|register
name|int
function_decl|(
modifier|*
name|oldproc
function_decl|)
parameter_list|()
function_decl|;
if|if
condition|(
operator|(
name|e
operator|=
name|XLookupExtension
argument_list|(
name|dpy
argument_list|,
name|extension
argument_list|)
operator|)
operator|==
name|NULL
condition|)
return|return
operator|(
name|NULL
operator|)
return|;
name|LockDisplay
argument_list|(
name|dpy
argument_list|)
expr_stmt|;
name|oldproc
operator|=
name|e
operator|->
name|free_Font
expr_stmt|;
name|e
operator|->
name|free_Font
operator|=
name|proc
expr_stmt|;
name|UnlockDisplay
argument_list|(
name|dpy
argument_list|)
expr_stmt|;
return|return
operator|(
name|oldproc
operator|)
return|;
block|}
end_block

begin_if
if|#
directive|if
name|NeedFunctionPrototypes
end_if

begin_macro
name|int
argument_list|(
argument|*XESetCloseDisplay(     Display* dpy,     int	extension,     int (*proc) (
if|#
directive|if
name|NeedNestedPrototypes
argument|Display*
comment|/* display */
argument|,               XExtCodes*
comment|/* codes */
endif|#
directive|endif
argument|) )
argument_list|)
end_macro

begin_expr_stmt
operator|(
if|#
directive|if
name|NeedNestedPrototypes
name|Display
operator|*
operator|,
name|XExtCodes
operator|*
endif|#
directive|endif
operator|)
else|#
directive|else
name|int
argument_list|(
argument|*XESetCloseDisplay(dpy, extension, proc)
argument_list|)
operator|(
operator|)
name|Display
operator|*
name|dpy
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* display */
end_comment

begin_decl_stmt
name|int
name|extension
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* extension number */
end_comment

begin_function_decl
name|int
function_decl|(
modifier|*
name|proc
function_decl|)
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* routine to call when display closed */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_block
block|{
specifier|register
name|_XExtension
modifier|*
name|e
decl_stmt|;
comment|/* for lookup of extension */
specifier|register
name|int
function_decl|(
modifier|*
name|oldproc
function_decl|)
parameter_list|()
function_decl|;
if|if
condition|(
operator|(
name|e
operator|=
name|XLookupExtension
argument_list|(
name|dpy
argument_list|,
name|extension
argument_list|)
operator|)
operator|==
name|NULL
condition|)
return|return
operator|(
name|NULL
operator|)
return|;
name|LockDisplay
argument_list|(
name|dpy
argument_list|)
expr_stmt|;
name|oldproc
operator|=
name|e
operator|->
name|close_display
expr_stmt|;
name|e
operator|->
name|close_display
operator|=
name|proc
expr_stmt|;
name|UnlockDisplay
argument_list|(
name|dpy
argument_list|)
expr_stmt|;
return|return
operator|(
name|oldproc
operator|)
return|;
block|}
end_block

begin_if
if|#
directive|if
name|NeedFunctionPrototypes
end_if

begin_macro
name|int
argument_list|(
argument|*XESetWireToEvent(     Display* dpy,     int event_number,     Bool (*proc) (
if|#
directive|if
name|NeedNestedPrototypes
argument|Display*
comment|/* display */
argument|,                XEvent*
comment|/* re */
argument|,                xEvent*
comment|/* event */
endif|#
directive|endif
argument|) )
argument_list|)
end_macro

begin_expr_stmt
operator|(
if|#
directive|if
name|NeedNestedPrototypes
name|Display
operator|*
operator|,
name|XEvent
operator|*
operator|,
name|xEvent
operator|*
endif|#
directive|endif
operator|)
else|#
directive|else
name|Bool
argument_list|(
argument|*XESetWireToEvent(dpy, event_number, proc)
argument_list|)
operator|(
operator|)
name|Display
operator|*
name|dpy
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* display */
end_comment

begin_function_decl
name|Bool
function_decl|(
modifier|*
name|proc
function_decl|)
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* routine to call when converting event */
end_comment

begin_decl_stmt
name|int
name|event_number
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* event routine to replace */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_block
block|{
specifier|register
name|Bool
function_decl|(
modifier|*
name|oldproc
function_decl|)
parameter_list|()
function_decl|;
if|if
condition|(
name|proc
operator|==
name|NULL
condition|)
name|proc
operator|=
name|_XUnknownWireEvent
expr_stmt|;
name|LockDisplay
argument_list|(
name|dpy
argument_list|)
expr_stmt|;
name|oldproc
operator|=
name|dpy
operator|->
name|event_vec
index|[
name|event_number
index|]
expr_stmt|;
name|dpy
operator|->
name|event_vec
index|[
name|event_number
index|]
operator|=
name|proc
expr_stmt|;
name|UnlockDisplay
argument_list|(
name|dpy
argument_list|)
expr_stmt|;
return|return
operator|(
name|oldproc
operator|)
return|;
block|}
end_block

begin_if
if|#
directive|if
name|NeedFunctionPrototypes
end_if

begin_macro
name|Status
argument_list|(
argument|*XESetEventToWire(     Display* dpy,     int	event_number,     int (*proc) (
if|#
directive|if
name|NeedNestedPrototypes
argument|Display*
comment|/* display */
argument|,               XEvent*
comment|/* re */
argument|,               xEvent*
comment|/* event */
endif|#
directive|endif
argument|) )
argument_list|)
end_macro

begin_expr_stmt
operator|(
if|#
directive|if
name|NeedNestedPrototypes
name|Display
operator|*
operator|,
name|XEvent
operator|*
operator|,
name|xEvent
operator|*
endif|#
directive|endif
operator|)
else|#
directive|else
name|Status
argument_list|(
argument|*XESetEventToWire(dpy, event_number, proc)
argument_list|)
operator|(
operator|)
name|Display
operator|*
name|dpy
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* display */
end_comment

begin_function_decl
name|Status
function_decl|(
modifier|*
name|proc
function_decl|)
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* routine to call when converting event */
end_comment

begin_decl_stmt
name|int
name|event_number
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* event routine to replace */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_block
block|{
specifier|register
name|Status
function_decl|(
modifier|*
name|oldproc
function_decl|)
parameter_list|()
function_decl|;
if|if
condition|(
name|proc
operator|==
name|NULL
condition|)
name|proc
operator|=
name|_XUnknownNativeEvent
expr_stmt|;
name|LockDisplay
argument_list|(
name|dpy
argument_list|)
expr_stmt|;
name|oldproc
operator|=
name|dpy
operator|->
name|wire_vec
index|[
name|event_number
index|]
expr_stmt|;
name|dpy
operator|->
name|wire_vec
index|[
name|event_number
index|]
operator|=
name|proc
expr_stmt|;
name|UnlockDisplay
argument_list|(
name|dpy
argument_list|)
expr_stmt|;
return|return
operator|(
name|oldproc
operator|)
return|;
block|}
end_block

begin_if
if|#
directive|if
name|NeedFunctionPrototypes
end_if

begin_macro
name|Status
argument_list|(
argument|*XESetWireToError(     Display* dpy,     int	error_number,     Bool (*proc) (
if|#
directive|if
name|NeedNestedPrototypes
argument|Display*
comment|/* display */
argument|, 	       XErrorEvent*
comment|/* he */
argument|, 	       xError*
comment|/* we */
endif|#
directive|endif
argument|) )
argument_list|)
end_macro

begin_expr_stmt
operator|(
if|#
directive|if
name|NeedNestedPrototypes
name|Display
operator|*
operator|,
name|XErrorEvent
operator|*
operator|,
name|xError
operator|*
endif|#
directive|endif
operator|)
else|#
directive|else
name|Bool
argument_list|(
argument|*XESetWireToError(dpy, error_number, proc)
argument_list|)
operator|(
operator|)
name|Display
operator|*
name|dpy
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* display */
end_comment

begin_function_decl
name|Bool
function_decl|(
modifier|*
name|proc
function_decl|)
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* routine to call when converting error */
end_comment

begin_decl_stmt
name|int
name|error_number
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* error routine to replace */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_block
block|{
specifier|register
name|Bool
function_decl|(
modifier|*
name|oldproc
function_decl|)
parameter_list|()
function_decl|;
if|if
condition|(
name|proc
operator|==
name|NULL
condition|)
name|proc
operator|=
name|_XDefaultWireError
expr_stmt|;
name|LockDisplay
argument_list|(
name|dpy
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|dpy
operator|->
name|error_vec
condition|)
block|{
name|int
name|i
decl_stmt|;
name|dpy
operator|->
name|error_vec
operator|=
operator|(
name|Bool
argument_list|(
operator|*
operator|*
argument_list|)
argument_list|()
operator|)
name|Xmalloc
argument_list|(
literal|256
operator|*
sizeof|sizeof
argument_list|(
name|oldproc
argument_list|)
argument_list|)
expr_stmt|;
for|for
control|(
name|i
operator|=
literal|1
init|;
name|i
operator|<
literal|256
condition|;
name|i
operator|++
control|)
name|dpy
operator|->
name|error_vec
index|[
name|i
index|]
operator|=
name|_XDefaultWireError
expr_stmt|;
block|}
if|if
condition|(
name|dpy
operator|->
name|error_vec
condition|)
block|{
name|oldproc
operator|=
name|dpy
operator|->
name|error_vec
index|[
name|error_number
index|]
expr_stmt|;
name|dpy
operator|->
name|error_vec
index|[
name|error_number
index|]
operator|=
name|proc
expr_stmt|;
block|}
name|UnlockDisplay
argument_list|(
name|dpy
argument_list|)
expr_stmt|;
return|return
operator|(
name|oldproc
operator|)
return|;
block|}
end_block

begin_if
if|#
directive|if
name|NeedFunctionPrototypes
end_if

begin_macro
name|int
argument_list|(
argument|*XESetError(     Display* dpy,     int	extension,     int (*proc) (
if|#
directive|if
name|NeedNestedPrototypes
argument|Display*
comment|/* display */
argument|,               xError*
comment|/* err */
argument|,               XExtCodes*
comment|/* codes */
argument|,               int*
comment|/* ret_code */
endif|#
directive|endif
argument|)
comment|/* proc */
argument|)
argument_list|)
end_macro

begin_expr_stmt
operator|(
if|#
directive|if
name|NeedNestedPrototypes
name|Display
operator|*
operator|,
name|xError
operator|*
operator|,
name|XExtCodes
operator|*
operator|,
name|int
operator|*
endif|#
directive|endif
operator|)
else|#
directive|else
name|int
argument_list|(
argument|*XESetError(dpy, extension, proc)
argument_list|)
operator|(
operator|)
name|Display
operator|*
name|dpy
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* display */
end_comment

begin_decl_stmt
name|int
name|extension
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* extension number */
end_comment

begin_function_decl
name|int
function_decl|(
modifier|*
name|proc
function_decl|)
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* routine to call when X error happens */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_block
block|{
specifier|register
name|_XExtension
modifier|*
name|e
decl_stmt|;
comment|/* for lookup of extension */
specifier|register
name|int
function_decl|(
modifier|*
name|oldproc
function_decl|)
parameter_list|()
function_decl|;
if|if
condition|(
operator|(
name|e
operator|=
name|XLookupExtension
argument_list|(
name|dpy
argument_list|,
name|extension
argument_list|)
operator|)
operator|==
name|NULL
condition|)
return|return
operator|(
name|NULL
operator|)
return|;
name|LockDisplay
argument_list|(
name|dpy
argument_list|)
expr_stmt|;
name|oldproc
operator|=
name|e
operator|->
name|error
expr_stmt|;
name|e
operator|->
name|error
operator|=
name|proc
expr_stmt|;
name|UnlockDisplay
argument_list|(
name|dpy
argument_list|)
expr_stmt|;
return|return
operator|(
name|oldproc
operator|)
return|;
block|}
end_block

begin_if
if|#
directive|if
name|NeedFunctionPrototypes
end_if

begin_macro
name|char
end_macro

begin_expr_stmt
operator|*
operator|(
operator|*
name|XESetErrorString
argument_list|(
argument|Display* dpy
argument_list|,
argument|int extension
argument_list|,
argument|char* (*proc) (
if|#
directive|if
name|NeedNestedPrototypes
argument|Display*
comment|/* display */
argument|,                 int
comment|/* code */
argument|,                 XExtCodes*
comment|/* codes */
argument|,                 char*
comment|/* buffer */
argument|,                 int
comment|/* nbytes */
endif|#
directive|endif
argument|)
argument_list|)
operator|)
operator|(
if|#
directive|if
name|NeedNestedPrototypes
name|Display
operator|*
operator|,
name|int
operator|,
name|XExtCodes
operator|*
operator|,
name|char
operator|*
operator|,
name|int
endif|#
directive|endif
operator|)
else|#
directive|else
name|char
operator|*
operator|(
operator|*
name|XESetErrorString
argument_list|(
name|dpy
argument_list|,
name|extension
argument_list|,
name|proc
argument_list|)
operator|)
operator|(
operator|)
name|Display
operator|*
name|dpy
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* display */
end_comment

begin_decl_stmt
name|int
name|extension
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* extension number */
end_comment

begin_function_decl
name|char
modifier|*
function_decl|(
modifier|*
name|proc
function_decl|)
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* routine to call when I/O error happens */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_block
block|{
specifier|register
name|_XExtension
modifier|*
name|e
decl_stmt|;
comment|/* for lookup of extension */
specifier|register
name|char
modifier|*
function_decl|(
modifier|*
name|oldproc
function_decl|)
parameter_list|()
function_decl|;
if|if
condition|(
operator|(
name|e
operator|=
name|XLookupExtension
argument_list|(
name|dpy
argument_list|,
name|extension
argument_list|)
operator|)
operator|==
name|NULL
condition|)
return|return
operator|(
name|NULL
operator|)
return|;
name|LockDisplay
argument_list|(
name|dpy
argument_list|)
expr_stmt|;
name|oldproc
operator|=
name|e
operator|->
name|error_string
expr_stmt|;
name|e
operator|->
name|error_string
operator|=
name|proc
expr_stmt|;
name|UnlockDisplay
argument_list|(
name|dpy
argument_list|)
expr_stmt|;
return|return
operator|(
name|oldproc
operator|)
return|;
block|}
end_block

begin_if
if|#
directive|if
name|NeedFunctionPrototypes
end_if

begin_macro
name|void
argument_list|(
argument|*XESetPrintErrorValues (     Display* dpy,     int extension,     void (*proc)(
if|#
directive|if
name|NeedNestedPrototypes
argument|Display*
comment|/* display */
argument|, 	      XErrorEvent*
comment|/* ev */
argument|, 	      void*
comment|/* fp */
endif|#
directive|endif
argument|) )
argument_list|)
end_macro

begin_expr_stmt
operator|(
if|#
directive|if
name|NeedNestedPrototypes
name|Display
operator|*
operator|,
name|XErrorEvent
operator|*
operator|,
name|void
operator|*
endif|#
directive|endif
operator|)
else|#
directive|else
name|void
argument_list|(
argument|*XESetPrintErrorValues(dpy, extension, proc)
argument_list|)
operator|(
operator|)
name|Display
operator|*
name|dpy
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* display */
end_comment

begin_decl_stmt
name|int
name|extension
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* extension number */
end_comment

begin_function_decl
name|void
function_decl|(
modifier|*
name|proc
function_decl|)
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* routine to call to print */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_block
block|{
specifier|register
name|_XExtension
modifier|*
name|e
decl_stmt|;
comment|/* for lookup of extension */
specifier|register
name|void
function_decl|(
modifier|*
name|oldproc
function_decl|)
parameter_list|()
function_decl|;
if|if
condition|(
operator|(
name|e
operator|=
name|XLookupExtension
argument_list|(
name|dpy
argument_list|,
name|extension
argument_list|)
operator|)
operator|==
name|NULL
condition|)
return|return
operator|(
name|NULL
operator|)
return|;
name|LockDisplay
argument_list|(
name|dpy
argument_list|)
expr_stmt|;
name|oldproc
operator|=
name|e
operator|->
name|error_values
expr_stmt|;
name|e
operator|->
name|error_values
operator|=
name|proc
expr_stmt|;
name|UnlockDisplay
argument_list|(
name|dpy
argument_list|)
expr_stmt|;
return|return
operator|(
name|oldproc
operator|)
return|;
block|}
end_block

end_unit

