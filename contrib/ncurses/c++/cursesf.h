begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// * This makes emacs happy -*-Mode: C++;-*-
end_comment

begin_comment
comment|/****************************************************************************  * Copyright (c) 1998,1999,2000 Free Software Foundation, Inc.              *  *                                                                          *  * Permission is hereby granted, free of charge, to any person obtaining a  *  * copy of this software and associated documentation files (the            *  * "Software"), to deal in the Software without restriction, including      *  * without limitation the rights to use, copy, modify, merge, publish,      *  * distribute, distribute with modifications, sublicense, and/or sell       *  * copies of the Software, and to permit persons to whom the Software is    *  * furnished to do so, subject to the following conditions:                 *  *                                                                          *  * The above copyright notice and this permission notice shall be included  *  * in all copies or substantial portions of the Software.                   *  *                                                                          *  * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS  *  * OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF               *  * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.   *  * IN NO EVENT SHALL THE ABOVE COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM,   *  * DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR    *  * OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR    *  * THE USE OR OTHER DEALINGS IN THE SOFTWARE.                               *  *                                                                          *  * Except as contained in this notice, the name(s) of the above copyright   *  * holders shall not be used in advertising or otherwise to promote the     *  * sale, use or other dealings in this Software without prior written       *  * authorization.                                                           *  ****************************************************************************/
end_comment

begin_comment
comment|/****************************************************************************  *   Author: Juergen Pfeifer<juergen.pfeifer@gmx.net> 1997                 *  ****************************************************************************/
end_comment

begin_comment
comment|// $Id: cursesf.h,v 1.12 2000/07/15 21:08:25 tom Exp $
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_CURSESF_H
end_ifndef

begin_define
define|#
directive|define
name|_CURSESF_H
end_define

begin_include
include|#
directive|include
file|<cursesp.h>
end_include

begin_include
include|#
directive|include
file|<string.h>
end_include

begin_extern
extern|extern
literal|"C"
block|{
include|#
directive|include
file|<form.h>
block|}
end_extern

begin_comment
comment|//
end_comment

begin_comment
comment|// -------------------------------------------------------------------------
end_comment

begin_comment
comment|// The abstract base class for buitin and user defined Fieldtypes.
end_comment

begin_comment
comment|// -------------------------------------------------------------------------
end_comment

begin_comment
comment|//
end_comment

begin_decl_stmt
name|class
name|NCursesFormField
decl_stmt|;
end_decl_stmt

begin_comment
comment|// forward declaration
end_comment

begin_comment
comment|// Class to represent builtin field types as well as C++ written new
end_comment

begin_comment
comment|// fieldtypes (see classes UserDefineFieldType...
end_comment

begin_decl_stmt
name|class
name|NCursesFieldType
block|{
name|friend
name|class
name|NCursesFormField
decl_stmt|;
name|protected
label|:
name|FIELDTYPE
modifier|*
name|fieldtype
decl_stmt|;
specifier|inline
name|void
name|OnError
argument_list|(
name|int
name|err
argument_list|)
decl|const
name|THROWS
argument_list|(
name|NCursesFormException
argument_list|)
block|{
if|if
condition|(
name|err
operator|!=
name|E_OK
condition|)
name|THROW
argument_list|(
argument|new NCursesFormException (err)
argument_list|)
empty_stmt|;
block|}
name|NCursesFieldType
argument_list|(
name|FIELDTYPE
operator|*
name|f
argument_list|)
operator|:
name|fieldtype
argument_list|(
argument|f
argument_list|)
block|{   }
name|virtual
operator|~
name|NCursesFieldType
argument_list|()
block|{}
comment|// Set the fields f fieldtype to this one.
name|virtual
name|void
name|set
argument_list|(
name|NCursesFormField
operator|&
name|f
argument_list|)
operator|=
literal|0
expr_stmt|;
name|public
label|:
name|NCursesFieldType
argument_list|()
operator|:
name|fieldtype
argument_list|(
argument|(FIELDTYPE*)
literal|0
argument_list|)
block|{   }
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|//
end_comment

begin_comment
comment|// -------------------------------------------------------------------------
end_comment

begin_comment
comment|// The class representing a forms field, wrapping the lowlevel FIELD struct
end_comment

begin_comment
comment|// -------------------------------------------------------------------------
end_comment

begin_comment
comment|//
end_comment

begin_decl_stmt
name|class
name|NCursesFormField
block|{
name|friend
name|class
name|NCursesForm
decl_stmt|;
name|protected
label|:
name|FIELD
modifier|*
name|field
decl_stmt|;
comment|// lowlevel structure
name|NCursesFieldType
modifier|*
name|ftype
decl_stmt|;
comment|// Associated field type
comment|// Error handler
specifier|inline
name|void
name|OnError
argument_list|(
name|int
name|err
argument_list|)
decl|const
name|THROWS
argument_list|(
name|NCursesFormException
argument_list|)
block|{
if|if
condition|(
name|err
operator|!=
name|E_OK
condition|)
name|THROW
argument_list|(
argument|new NCursesFormException (err)
argument_list|)
empty_stmt|;
block|}
name|public
label|:
comment|// Create a 'Null' field. Can be used to delimit a field list
name|NCursesFormField
argument_list|()
operator|:
name|field
argument_list|(
operator|(
name|FIELD
operator|*
operator|)
literal|0
argument_list|)
operator|,
name|ftype
argument_list|(
argument|(NCursesFieldType*)
literal|0
argument_list|)
block|{   }
comment|// Create a new field
name|NCursesFormField
argument_list|(
argument|int rows
argument_list|,
argument|int cols
argument_list|,
argument|int first_row =
literal|0
argument_list|,
argument|int first_col =
literal|0
argument_list|,
argument|int offscreen_rows =
literal|0
argument_list|,
argument|int additional_buffers =
literal|0
argument_list|)
operator|:
name|ftype
argument_list|(
argument|(NCursesFieldType*)
literal|0
argument_list|)
block|{
name|field
operator|=
operator|::
name|new_field
argument_list|(
name|rows
argument_list|,
name|cols
argument_list|,
name|first_row
argument_list|,
name|first_col
argument_list|,
name|offscreen_rows
argument_list|,
name|additional_buffers
argument_list|)
block|;
if|if
condition|(
operator|!
name|field
condition|)
name|OnError
argument_list|(
name|errno
argument_list|)
expr_stmt|;
block|}
name|virtual
operator|~
name|NCursesFormField
argument_list|()
expr_stmt|;
comment|// Duplicate the field at a new position
specifier|inline
name|NCursesFormField
modifier|*
name|dup
parameter_list|(
name|int
name|first_row
parameter_list|,
name|int
name|first_col
parameter_list|)
block|{
name|NCursesFormField
modifier|*
name|f
init|=
name|new
name|NCursesFormField
argument_list|()
decl_stmt|;
if|if
condition|(
operator|!
name|f
condition|)
name|OnError
argument_list|(
name|E_SYSTEM_ERROR
argument_list|)
expr_stmt|;
else|else
block|{
name|f
operator|->
name|ftype
operator|=
name|ftype
expr_stmt|;
name|f
operator|->
name|field
operator|=
operator|::
name|dup_field
argument_list|(
name|field
argument_list|,
name|first_row
argument_list|,
name|first_col
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|f
operator|->
name|field
condition|)
name|OnError
argument_list|(
name|errno
argument_list|)
expr_stmt|;
block|}
return|return
name|f
return|;
block|}
comment|// Link the field to a new location
specifier|inline
name|NCursesFormField
modifier|*
name|link
parameter_list|(
name|int
name|first_row
parameter_list|,
name|int
name|first_col
parameter_list|)
block|{
name|NCursesFormField
modifier|*
name|f
init|=
name|new
name|NCursesFormField
argument_list|()
decl_stmt|;
if|if
condition|(
operator|!
name|f
condition|)
name|OnError
argument_list|(
name|E_SYSTEM_ERROR
argument_list|)
expr_stmt|;
else|else
block|{
name|f
operator|->
name|ftype
operator|=
name|ftype
expr_stmt|;
name|f
operator|->
name|field
operator|=
operator|::
name|link_field
argument_list|(
name|field
argument_list|,
name|first_row
argument_list|,
name|first_col
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|f
operator|->
name|field
condition|)
name|OnError
argument_list|(
name|errno
argument_list|)
expr_stmt|;
block|}
return|return
name|f
return|;
block|}
comment|// Get the lowlevel field representation
specifier|inline
name|FIELD
operator|*
name|get_field
argument_list|()
specifier|const
block|{
return|return
name|field
return|;
block|}
comment|// Retrieve info about the field
specifier|inline
name|void
name|info
argument_list|(
name|int
operator|&
name|rows
argument_list|,
name|int
operator|&
name|cols
argument_list|,
name|int
operator|&
name|first_row
argument_list|,
name|int
operator|&
name|first_col
argument_list|,
name|int
operator|&
name|offscreen_rows
argument_list|,
name|int
operator|&
name|additional_buffers
argument_list|)
decl|const
block|{
name|OnError
argument_list|(
operator|::
name|field_info
argument_list|(
name|field
argument_list|,
operator|&
name|rows
argument_list|,
operator|&
name|cols
argument_list|,
operator|&
name|first_row
argument_list|,
operator|&
name|first_col
argument_list|,
operator|&
name|offscreen_rows
argument_list|,
operator|&
name|additional_buffers
argument_list|)
argument_list|)
expr_stmt|;
block|}
comment|// Retrieve info about the fields dynamic properties.
specifier|inline
name|void
name|dynamic_info
argument_list|(
name|int
operator|&
name|dynamic_rows
argument_list|,
name|int
operator|&
name|dynamic_cols
argument_list|,
name|int
operator|&
name|max_growth
argument_list|)
decl|const
block|{
name|OnError
argument_list|(
operator|::
name|dynamic_field_info
argument_list|(
name|field
argument_list|,
operator|&
name|dynamic_rows
argument_list|,
operator|&
name|dynamic_cols
argument_list|,
operator|&
name|max_growth
argument_list|)
argument_list|)
expr_stmt|;
block|}
comment|// For a dynamic field you may set the maximum growth limit.
comment|// A zero means unlimited growth.
specifier|inline
name|void
name|set_maximum_growth
parameter_list|(
name|int
name|growth
init|=
literal|0
parameter_list|)
block|{
name|OnError
argument_list|(
operator|::
name|set_max_field
argument_list|(
name|field
argument_list|,
name|growth
argument_list|)
argument_list|)
expr_stmt|;
block|}
comment|// Move the field to a new position
specifier|inline
name|void
name|move
parameter_list|(
name|int
name|row
parameter_list|,
name|int
name|col
parameter_list|)
block|{
name|OnError
argument_list|(
operator|::
name|move_field
argument_list|(
name|field
argument_list|,
name|row
argument_list|,
name|col
argument_list|)
argument_list|)
expr_stmt|;
block|}
comment|// Mark the field to start a new page
specifier|inline
name|void
name|new_page
parameter_list|(
name|bool
name|pageFlag
init|=
name|FALSE
parameter_list|)
block|{
name|OnError
argument_list|(
operator|::
name|set_new_page
argument_list|(
name|field
argument_list|,
name|pageFlag
argument_list|)
argument_list|)
expr_stmt|;
block|}
comment|// Retrieve whether or not the field starts a new page.
specifier|inline
name|bool
name|is_new_page
argument_list|()
specifier|const
block|{
return|return
operator|::
name|new_page
argument_list|(
name|field
argument_list|)
return|;
block|}
comment|// Set the justification for the field
specifier|inline
name|void
name|set_justification
parameter_list|(
name|int
name|just
parameter_list|)
block|{
name|OnError
argument_list|(
operator|::
name|set_field_just
argument_list|(
name|field
argument_list|,
name|just
argument_list|)
argument_list|)
expr_stmt|;
block|}
comment|// Retrieve the fields justification
specifier|inline
name|int
name|justification
argument_list|()
specifier|const
block|{
return|return
operator|::
name|field_just
argument_list|(
name|field
argument_list|)
return|;
block|}
comment|// Set the foreground attribute for the field
specifier|inline
name|void
name|set_foreground
parameter_list|(
name|chtype
name|fore
parameter_list|)
block|{
name|OnError
argument_list|(
operator|::
name|set_field_fore
argument_list|(
name|field
argument_list|,
name|fore
argument_list|)
argument_list|)
expr_stmt|;
block|}
comment|// Retrieve the fields foreground attribute
specifier|inline
name|chtype
name|fore
argument_list|()
specifier|const
block|{
return|return
operator|::
name|field_fore
argument_list|(
name|field
argument_list|)
return|;
block|}
comment|// Set the background attribute for the field
specifier|inline
name|void
name|set_background
parameter_list|(
name|chtype
name|back
parameter_list|)
block|{
name|OnError
argument_list|(
operator|::
name|set_field_back
argument_list|(
name|field
argument_list|,
name|back
argument_list|)
argument_list|)
expr_stmt|;
block|}
comment|// Retrieve the fields background attribute
specifier|inline
name|chtype
name|back
argument_list|()
specifier|const
block|{
return|return
operator|::
name|field_back
argument_list|(
name|field
argument_list|)
return|;
block|}
comment|// Set the padding character for the field
specifier|inline
name|void
name|set_pad_character
parameter_list|(
name|int
name|pad
parameter_list|)
block|{
name|OnError
argument_list|(
operator|::
name|set_field_pad
argument_list|(
name|field
argument_list|,
name|pad
argument_list|)
argument_list|)
expr_stmt|;
block|}
comment|// Retrieve the fields padding character
specifier|inline
name|int
name|pad
argument_list|()
specifier|const
block|{
return|return
operator|::
name|field_pad
argument_list|(
name|field
argument_list|)
return|;
block|}
comment|// Switch on the fields options
specifier|inline
name|void
name|options_on
parameter_list|(
name|Field_Options
name|options
parameter_list|)
block|{
name|OnError
argument_list|(
operator|::
name|field_opts_on
argument_list|(
name|field
argument_list|,
name|options
argument_list|)
argument_list|)
expr_stmt|;
block|}
comment|// Switch off the fields options
specifier|inline
name|void
name|options_off
parameter_list|(
name|Field_Options
name|options
parameter_list|)
block|{
name|OnError
argument_list|(
operator|::
name|field_opts_off
argument_list|(
name|field
argument_list|,
name|options
argument_list|)
argument_list|)
expr_stmt|;
block|}
comment|// Retrieve the fields options
specifier|inline
name|Field_Options
name|options
argument_list|()
specifier|const
block|{
return|return
operator|::
name|field_opts
argument_list|(
name|field
argument_list|)
return|;
block|}
comment|// Set the fields options
specifier|inline
name|void
name|set_options
parameter_list|(
name|Field_Options
name|options
parameter_list|)
block|{
name|OnError
argument_list|(
operator|::
name|set_field_opts
argument_list|(
name|field
argument_list|,
name|options
argument_list|)
argument_list|)
expr_stmt|;
block|}
comment|// Mark the field as changed
specifier|inline
name|void
name|set_changed
parameter_list|(
name|bool
name|changeFlag
init|=
name|TRUE
parameter_list|)
block|{
name|OnError
argument_list|(
operator|::
name|set_field_status
argument_list|(
name|field
argument_list|,
name|changeFlag
argument_list|)
argument_list|)
expr_stmt|;
block|}
comment|// Test whether or not the field is marked as changed
specifier|inline
name|bool
name|changed
argument_list|()
specifier|const
block|{
return|return
operator|::
name|field_status
argument_list|(
name|field
argument_list|)
return|;
block|}
comment|// Return the index of the field in the field array of a form
comment|// or -1 if the field is not associated to a form
specifier|inline
name|int
argument_list|(
argument|index
argument_list|)
operator|(
operator|)
specifier|const
block|{
return|return
operator|::
name|field_index
argument_list|(
name|field
argument_list|)
return|;
block|}
comment|// Store a value in a fields buffer. The default buffer is nr. 0
specifier|inline
name|void
name|set_value
parameter_list|(
specifier|const
name|char
modifier|*
name|val
parameter_list|,
name|int
name|buffer
init|=
literal|0
parameter_list|)
block|{
name|OnError
argument_list|(
operator|::
name|set_field_buffer
argument_list|(
name|field
argument_list|,
name|buffer
argument_list|,
name|val
argument_list|)
argument_list|)
expr_stmt|;
block|}
comment|// Retrieve the value of a fields buffer. The defaukt buffer is nr. 0
specifier|inline
name|char
modifier|*
name|value
argument_list|(
name|int
name|buffer
operator|=
literal|0
argument_list|)
decl|const
block|{
return|return
operator|::
name|field_buffer
argument_list|(
name|field
argument_list|,
name|buffer
argument_list|)
return|;
block|}
comment|// Set the validation type of the field.
specifier|inline
name|void
name|set_fieldtype
parameter_list|(
name|NCursesFieldType
modifier|&
name|f
parameter_list|)
block|{
name|ftype
operator|=
operator|&
name|f
expr_stmt|;
name|f
operator|.
name|set
argument_list|(
operator|*
name|this
argument_list|)
expr_stmt|;
comment|// A good friend may do that...
block|}
comment|// Retrieve the validation type of the field.
specifier|inline
name|NCursesFieldType
operator|*
name|fieldtype
argument_list|()
specifier|const
block|{
return|return
name|ftype
return|;
block|}
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|//
end_comment

begin_comment
comment|// -------------------------------------------------------------------------
end_comment

begin_comment
comment|// The class representing a form, wrapping the lowlevel FORM struct
end_comment

begin_comment
comment|// -------------------------------------------------------------------------
end_comment

begin_comment
comment|//
end_comment

begin_decl_stmt
name|class
name|NCursesForm
range|:
name|public
name|NCursesPanel
block|{
name|protected
operator|:
name|FORM
operator|*
name|form
block|;
comment|// the lowlevel structure
name|private
operator|:
name|NCursesWindow
operator|*
name|sub
block|;
comment|// the subwindow object
name|bool
name|b_sub_owner
block|;
comment|// is this our own subwindow?
name|bool
name|b_framed
block|;
comment|// has the form a border?
name|bool
name|b_autoDelete
block|;
comment|// Delete fields when deleting form?
name|NCursesFormField
operator|*
operator|*
name|my_fields
block|;
comment|// The array of fields for this form
comment|// This structure is used for the form's user data field to link the
comment|// FORM* to the C++ object and to provide extra space for a user pointer.
typedef|typedef
struct|struct
block|{
name|void
modifier|*
name|m_user
decl_stmt|;
comment|// the pointer for the user's data
specifier|const
name|NCursesForm
modifier|*
name|m_back
decl_stmt|;
comment|// backward pointer to C++ object
specifier|const
name|FORM
modifier|*
name|m_owner
decl_stmt|;
block|}
name|UserHook
expr_stmt|;
comment|// Get the backward pointer to the C++ object from a FORM
specifier|static
specifier|inline
name|NCursesForm
operator|*
name|getHook
argument_list|(
argument|const FORM *f
argument_list|)
block|{
name|UserHook
operator|*
name|hook
operator|=
operator|(
name|UserHook
operator|*
operator|)
operator|::
name|form_userptr
argument_list|(
name|f
argument_list|)
block|;
name|assert
argument_list|(
name|hook
operator|!=
literal|0
operator|&&
name|hook
operator|->
name|m_owner
operator|==
name|f
argument_list|)
block|;
return|return
operator|(
name|NCursesForm
operator|*
operator|)
operator|(
name|hook
operator|->
name|m_back
operator|)
return|;
block|}
comment|// This are the built-in hook functions in this C++ binding. In C++ we use
comment|// virtual member functions (see below On_..._Init and On_..._Termination)
comment|// to provide this functionality in an object oriented manner.
specifier|static
name|void
name|frm_init
argument_list|(
name|FORM
operator|*
argument_list|)
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|static
name|void
name|frm_term
parameter_list|(
name|FORM
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|void
name|fld_init
parameter_list|(
name|FORM
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|void
name|fld_term
parameter_list|(
name|FORM
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|// Calculate FIELD* array for the menu
end_comment

begin_function_decl
name|FIELD
modifier|*
modifier|*
name|mapFields
parameter_list|(
name|NCursesFormField
modifier|*
name|nfields
index|[]
parameter_list|)
function_decl|;
end_function_decl

begin_label
name|protected
label|:
end_label

begin_comment
comment|// internal routines
end_comment

begin_function
specifier|inline
name|void
name|set_user
parameter_list|(
name|void
modifier|*
name|user
parameter_list|)
block|{
name|UserHook
modifier|*
name|uptr
init|=
operator|(
name|UserHook
operator|*
operator|)
operator|::
name|form_userptr
argument_list|(
name|form
argument_list|)
decl_stmt|;
name|assert
argument_list|(
name|uptr
operator|!=
literal|0
operator|&&
name|uptr
operator|->
name|m_back
operator|==
name|this
operator|&&
name|uptr
operator|->
name|m_owner
operator|==
name|form
argument_list|)
expr_stmt|;
name|uptr
operator|->
name|m_user
operator|=
name|user
expr_stmt|;
block|}
end_function

begin_function
specifier|inline
name|void
modifier|*
name|get_user
parameter_list|()
block|{
name|UserHook
modifier|*
name|uptr
init|=
operator|(
name|UserHook
operator|*
operator|)
operator|::
name|form_userptr
argument_list|(
name|form
argument_list|)
decl_stmt|;
name|assert
argument_list|(
name|uptr
operator|!=
literal|0
operator|&&
name|uptr
operator|->
name|m_back
operator|==
name|this
operator|&&
name|uptr
operator|->
name|m_owner
operator|==
name|form
argument_list|)
expr_stmt|;
return|return
name|uptr
operator|->
name|m_user
return|;
block|}
end_function

begin_function_decl
name|void
name|InitForm
parameter_list|(
name|NCursesFormField
modifier|*
name|Fields
index|[]
parameter_list|,
name|bool
name|with_frame
parameter_list|,
name|bool
name|autoDeleteFields
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
specifier|inline
name|void
name|OnError
argument_list|(
name|int
name|err
argument_list|)
decl|const
name|THROWS
argument_list|(
name|NCursesFormException
argument_list|)
block|{
if|if
condition|(
name|err
operator|!=
name|E_OK
condition|)
name|THROW
argument_list|(
argument|new NCursesFormException (err)
argument_list|)
empty_stmt|;
block|}
end_decl_stmt

begin_comment
comment|// this wraps the form_driver call.
end_comment

begin_function_decl
name|virtual
name|int
name|driver
parameter_list|(
name|int
name|c
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|// 'Internal' constructor, builds an object without association to a
end_comment

begin_comment
comment|// field array.
end_comment

begin_macro
name|NCursesForm
argument_list|(
argument|int  lines
argument_list|,
argument|int  cols
argument_list|,
argument|int  begin_y =
literal|0
argument_list|,
argument|int  begin_x =
literal|0
argument_list|)
end_macro

begin_expr_stmt
unit|:
name|NCursesPanel
argument_list|(
name|lines
argument_list|,
name|cols
argument_list|,
name|begin_y
argument_list|,
name|begin_x
argument_list|)
operator|,
name|form
argument_list|(
argument|(FORM*)
literal|0
argument_list|)
block|{   }
name|public
operator|:
comment|// Create form for the default panel.
name|NCursesForm
argument_list|(
argument|NCursesFormField* Fields[]
argument_list|,
argument|bool with_frame=FALSE
argument_list|,
comment|// reserve space for a frame?
argument|bool autoDelete_Fields=FALSE
argument_list|)
comment|// do automatic cleanup?
operator|:
name|NCursesPanel
argument_list|()
block|{
name|InitForm
argument_list|(
name|Fields
argument_list|,
name|with_frame
argument_list|,
name|autoDelete_Fields
argument_list|)
block|;   }
comment|// Create a form in a panel with the given position and size.
name|NCursesForm
argument_list|(
argument|NCursesFormField* Fields[]
argument_list|,
argument|int  lines
argument_list|,
argument|int  cols
argument_list|,
argument|int  begin_y
argument_list|,
argument|int  begin_x
argument_list|,
argument|bool with_frame=FALSE
argument_list|,
comment|// reserve space for a frame?
argument|bool autoDelete_Fields=FALSE
argument_list|)
comment|// do automatic cleanup?
operator|:
name|NCursesPanel
argument_list|(
argument|lines
argument_list|,
argument|cols
argument_list|,
argument|begin_y
argument_list|,
argument|begin_x
argument_list|)
block|{
name|InitForm
argument_list|(
name|Fields
argument_list|,
name|with_frame
argument_list|,
name|autoDelete_Fields
argument_list|)
block|;   }
name|virtual
operator|~
name|NCursesForm
argument_list|()
expr_stmt|;
end_expr_stmt

begin_comment
comment|// Set the default attributes for the form
end_comment

begin_function_decl
name|virtual
name|void
name|setDefaultAttributes
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|// Retrieve current field of the form.
end_comment

begin_expr_stmt
specifier|inline
name|NCursesFormField
operator|*
name|current_field
argument_list|()
specifier|const
block|{
return|return
name|my_fields
index|[
operator|::
name|field_index
argument_list|(
operator|::
name|current_field
argument_list|(
name|form
argument_list|)
argument_list|)
index|]
return|;
block|}
end_expr_stmt

begin_comment
comment|// Set the forms subwindow
end_comment

begin_function_decl
name|void
name|setSubWindow
parameter_list|(
name|NCursesWindow
modifier|&
name|sub
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|// Set these fields for the form
end_comment

begin_function
specifier|inline
name|void
name|setFields
parameter_list|(
name|NCursesFormField
modifier|*
name|Fields
index|[]
parameter_list|)
block|{
name|OnError
argument_list|(
operator|::
name|set_form_fields
argument_list|(
name|form
argument_list|,
name|mapFields
argument_list|(
name|Fields
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|// Remove the form from the screen
end_comment

begin_function
specifier|inline
name|void
name|unpost
parameter_list|(
name|void
parameter_list|)
block|{
name|OnError
argument_list|(
operator|::
name|unpost_form
argument_list|(
name|form
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|// Post the form to the screen if flag is true, unpost it otherwise
end_comment

begin_function
specifier|inline
name|void
name|post
parameter_list|(
name|bool
name|flag
init|=
name|TRUE
parameter_list|)
block|{
name|OnError
argument_list|(
name|flag
condition|?
operator|::
name|post_form
argument_list|(
name|form
argument_list|)
else|:
operator|::
name|unpost_form
argument_list|(
name|form
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|// Decorations
end_comment

begin_function
specifier|inline
name|void
name|frame
parameter_list|(
specifier|const
name|char
modifier|*
name|title
init|=
name|NULL
parameter_list|,
specifier|const
name|char
modifier|*
name|btitle
init|=
name|NULL
parameter_list|)
block|{
if|if
condition|(
name|b_framed
condition|)
name|NCursesPanel
operator|::
name|frame
argument_list|(
name|title
argument_list|,
name|btitle
argument_list|)
expr_stmt|;
else|else
name|OnError
argument_list|(
name|E_SYSTEM_ERROR
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
specifier|inline
name|void
name|boldframe
parameter_list|(
specifier|const
name|char
modifier|*
name|title
init|=
name|NULL
parameter_list|,
specifier|const
name|char
modifier|*
name|btitle
init|=
name|NULL
parameter_list|)
block|{
if|if
condition|(
name|b_framed
condition|)
name|NCursesPanel
operator|::
name|boldframe
argument_list|(
name|title
argument_list|,
name|btitle
argument_list|)
expr_stmt|;
else|else
name|OnError
argument_list|(
name|E_SYSTEM_ERROR
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
specifier|inline
name|void
name|label
parameter_list|(
specifier|const
name|char
modifier|*
name|topLabel
parameter_list|,
specifier|const
name|char
modifier|*
name|bottomLabel
parameter_list|)
block|{
if|if
condition|(
name|b_framed
condition|)
name|NCursesPanel
operator|::
name|label
argument_list|(
name|topLabel
argument_list|,
name|bottomLabel
argument_list|)
expr_stmt|;
else|else
name|OnError
argument_list|(
name|E_SYSTEM_ERROR
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|// -----
end_comment

begin_comment
comment|// Hooks
end_comment

begin_comment
comment|// -----
end_comment

begin_comment
comment|// Called after the form gets repositioned in its window.
end_comment

begin_comment
comment|// This is especially true if the form is posted.
end_comment

begin_function_decl
name|virtual
name|void
name|On_Form_Init
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|// Called before the form gets repositioned in its window.
end_comment

begin_comment
comment|// This is especially true if the form is unposted.
end_comment

begin_function_decl
name|virtual
name|void
name|On_Form_Termination
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|// Called after the field became the current field
end_comment

begin_function_decl
name|virtual
name|void
name|On_Field_Init
parameter_list|(
name|NCursesFormField
modifier|&
name|field
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|// Called before this field is left as current field.
end_comment

begin_function_decl
name|virtual
name|void
name|On_Field_Termination
parameter_list|(
name|NCursesFormField
modifier|&
name|field
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|// Calculate required window size for the form.
end_comment

begin_decl_stmt
name|void
name|scale
argument_list|(
name|int
operator|&
name|rows
argument_list|,
name|int
operator|&
name|cols
argument_list|)
decl|const
block|{
name|OnError
argument_list|(
operator|::
name|scale_form
argument_list|(
name|form
argument_list|,
operator|&
name|rows
argument_list|,
operator|&
name|cols
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_decl_stmt

begin_comment
comment|// Retrieve number of fields in the form.
end_comment

begin_expr_stmt
name|int
name|count
argument_list|()
specifier|const
block|{
return|return
operator|::
name|field_count
argument_list|(
name|form
argument_list|)
return|;
block|}
end_expr_stmt

begin_comment
comment|// Make the page the current page of the form.
end_comment

begin_function
name|void
name|set_page
parameter_list|(
name|int
name|page
parameter_list|)
block|{
name|OnError
argument_list|(
operator|::
name|set_form_page
argument_list|(
name|form
argument_list|,
name|page
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|// Retrieve current page number
end_comment

begin_expr_stmt
name|int
name|page
argument_list|()
specifier|const
block|{
return|return
operator|::
name|form_page
argument_list|(
name|form
argument_list|)
return|;
block|}
end_expr_stmt

begin_comment
comment|// Switch on the forms options
end_comment

begin_function
specifier|inline
name|void
name|options_on
parameter_list|(
name|Form_Options
name|options
parameter_list|)
block|{
name|OnError
argument_list|(
operator|::
name|form_opts_on
argument_list|(
name|form
argument_list|,
name|options
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|// Switch off the forms options
end_comment

begin_function
specifier|inline
name|void
name|options_off
parameter_list|(
name|Form_Options
name|options
parameter_list|)
block|{
name|OnError
argument_list|(
operator|::
name|form_opts_off
argument_list|(
name|form
argument_list|,
name|options
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|// Retrieve the forms options
end_comment

begin_expr_stmt
specifier|inline
name|Form_Options
name|options
argument_list|()
specifier|const
block|{
return|return
operator|::
name|form_opts
argument_list|(
name|form
argument_list|)
return|;
block|}
end_expr_stmt

begin_comment
comment|// Set the forms options
end_comment

begin_function
specifier|inline
name|void
name|set_options
parameter_list|(
name|Form_Options
name|options
parameter_list|)
block|{
name|OnError
argument_list|(
operator|::
name|set_form_opts
argument_list|(
name|form
argument_list|,
name|options
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|// Are there more data in the current field after the data shown
end_comment

begin_expr_stmt
specifier|inline
name|bool
name|data_ahead
argument_list|()
specifier|const
block|{
return|return
operator|::
name|data_ahead
argument_list|(
name|form
argument_list|)
return|;
block|}
end_expr_stmt

begin_comment
comment|// Are there more data in the current field before the data shown
end_comment

begin_expr_stmt
specifier|inline
name|bool
name|data_behind
argument_list|()
specifier|const
block|{
return|return
operator|::
name|data_behind
argument_list|(
name|form
argument_list|)
return|;
block|}
end_expr_stmt

begin_comment
comment|// Position the cursor to the current field
end_comment

begin_function
specifier|inline
name|void
name|position_cursor
parameter_list|()
block|{
name|OnError
argument_list|(
operator|::
name|pos_form_cursor
argument_list|(
name|form
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|// Set the current field
end_comment

begin_function
specifier|inline
name|void
name|set_current
parameter_list|(
name|NCursesFormField
modifier|&
name|F
parameter_list|)
block|{
name|OnError
argument_list|(
operator|::
name|set_current_field
argument_list|(
name|form
argument_list|,
name|F
operator|.
name|field
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|// Provide a default key virtualization. Translate the keyboard
end_comment

begin_comment
comment|// code c into a form request code.
end_comment

begin_comment
comment|// The default implementation provides a hopefully straightforward
end_comment

begin_comment
comment|// mapping for the most common keystrokes and form requests.
end_comment

begin_function_decl
name|virtual
name|int
name|virtualize
parameter_list|(
name|int
name|c
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|// Operators
end_comment

begin_decl_stmt
specifier|inline
name|NCursesFormField
modifier|*
name|operator
index|[]
argument_list|(
name|int
name|i
argument_list|)
decl|const
block|{
if|if
condition|(
operator|(
name|i
operator|<
literal|0
operator|)
operator|||
operator|(
name|i
operator|>=
operator|::
name|field_count
argument_list|(
name|form
argument_list|)
operator|)
condition|)
name|OnError
argument_list|(
name|E_BAD_ARGUMENT
argument_list|)
expr_stmt|;
return|return
name|my_fields
index|[
name|i
index|]
return|;
block|}
end_decl_stmt

begin_comment
comment|// Perform the menu's operation
end_comment

begin_comment
comment|// Return the field where you left the form.
end_comment

begin_expr_stmt
name|virtual
name|NCursesFormField
operator|*
name|operator
argument_list|()
argument_list|(
name|void
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|// Exception handlers. The default is a Beep.
end_comment

begin_decl_stmt
name|virtual
name|void
name|On_Request_Denied
argument_list|(
name|int
name|c
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|virtual
name|void
name|On_Invalid_Field
argument_list|(
name|int
name|c
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|virtual
name|void
name|On_Unknown_Command
argument_list|(
name|int
name|c
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_comment
unit|};
comment|//
end_comment

begin_comment
comment|// -------------------------------------------------------------------------
end_comment

begin_comment
comment|// This is the typical C++ typesafe way to allow to attach
end_comment

begin_comment
comment|// user data to a field of a form. Its assumed that the user
end_comment

begin_comment
comment|// data belongs to some class T. Use T as template argument
end_comment

begin_comment
comment|// to create a UserField.
end_comment

begin_comment
comment|// -------------------------------------------------------------------------
end_comment

begin_expr_stmt
name|template
operator|<
name|class
name|T
operator|>
name|class
name|NCursesUserField
operator|:
name|public
name|NCursesFormField
block|{
name|public
operator|:
name|NCursesUserField
argument_list|(
argument|int rows
argument_list|,
argument|int cols
argument_list|,
argument|int first_row =
literal|0
argument_list|,
argument|int first_col =
literal|0
argument_list|,
argument|const T* p_UserData = (T*)
literal|0
argument_list|,
argument|int offscreen_rows =
literal|0
argument_list|,
argument|int additional_buffers =
literal|0
argument_list|)
operator|:
name|NCursesFormField
argument_list|(
argument|rows
argument_list|,
argument|cols
argument_list|,
argument|first_row
argument_list|,
argument|first_col
argument_list|,
argument|offscreen_rows
argument_list|,
argument|additional_buffers
argument_list|)
block|{
if|if
condition|(
name|field
condition|)
name|OnError
argument_list|(
operator|::
name|set_field_userptr
argument_list|(
name|field
argument_list|,
operator|(
name|void
operator|*
operator|)
name|p_UserData
argument_list|)
argument_list|)
expr_stmt|;
block|}
name|virtual
operator|~
name|NCursesUserField
argument_list|()
block|{}
expr_stmt|;
end_expr_stmt

begin_decl_stmt
specifier|inline
specifier|const
name|T
modifier|*
name|UserData
argument_list|(
name|void
argument_list|)
decl|const
block|{
return|return
operator|(
specifier|const
name|T
operator|*
operator|)
operator|::
name|field_userptr
argument_list|(
name|field
argument_list|)
return|;
block|}
end_decl_stmt

begin_function
specifier|inline
name|virtual
name|void
name|setUserData
parameter_list|(
specifier|const
name|T
modifier|*
name|p_UserData
parameter_list|)
block|{
if|if
condition|(
name|field
condition|)
name|OnError
argument_list|(
operator|::
name|set_field_userptr
argument_list|(
name|field
argument_list|,
operator|(
name|void
operator|*
operator|)
name|p_UserData
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
unit|};
comment|//
end_comment

begin_comment
comment|// -------------------------------------------------------------------------
end_comment

begin_comment
comment|// The same mechanism is used to attach user data to a form
end_comment

begin_comment
comment|// -------------------------------------------------------------------------
end_comment

begin_comment
comment|//
end_comment

begin_expr_stmt
name|template
operator|<
name|class
name|T
operator|>
name|class
name|NCursesUserForm
operator|:
name|public
name|NCursesForm
block|{
name|protected
operator|:
comment|// 'Internal' constructor, builds an object without association to a
comment|// field array.
name|NCursesUserForm
argument_list|(
argument|int  lines
argument_list|,
argument|int  cols
argument_list|,
argument|int  begin_y =
literal|0
argument_list|,
argument|int  begin_x =
literal|0
argument_list|,
argument|const T* p_UserData = (T*)
literal|0
argument_list|)
operator|:
name|NCursesForm
argument_list|(
argument|lines
argument_list|,
argument|cols
argument_list|,
argument|begin_y
argument_list|,
argument|begin_x
argument_list|)
block|{
if|if
condition|(
name|form
condition|)
name|set_user
argument_list|(
operator|(
name|void
operator|*
operator|)
name|p_UserData
argument_list|)
expr_stmt|;
block|}
name|public
operator|:
name|NCursesUserForm
argument_list|(
argument|NCursesFormField Fields[]
argument_list|,
argument|bool with_frame=FALSE
argument_list|,
argument|bool autoDelete_Fields=FALSE
argument_list|)
operator|:
name|NCursesForm
argument_list|(
argument|Fields
argument_list|,
argument|with_frame
argument_list|,
argument|autoDelete_Fields
argument_list|)
block|{   }
expr_stmt|;
end_expr_stmt

begin_macro
name|NCursesUserForm
argument_list|(
argument|NCursesFormField Fields[]
argument_list|,
argument|const T* p_UserData = (T*)
literal|0
argument_list|,
argument|bool with_frame=FALSE
argument_list|,
argument|bool autoDelete_Fields=FALSE
argument_list|)
end_macro

begin_macro
unit|:
name|NCursesForm
argument_list|(
argument|Fields
argument_list|,
argument|with_frame
argument_list|,
argument|autoDelete_Fields
argument_list|)
end_macro

begin_block
block|{
if|if
condition|(
name|form
condition|)
name|set_user
argument_list|(
operator|(
name|void
operator|*
operator|)
name|p_UserData
argument_list|)
expr_stmt|;
block|}
end_block

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|NCursesUserForm
argument_list|(
argument|NCursesFormField Fields[]
argument_list|,
argument|int lines
argument_list|,
argument|int cols
argument_list|,
argument|int begin_y =
literal|0
argument_list|,
argument|int begin_x =
literal|0
argument_list|,
argument|const T* p_UserData = (T*)
literal|0
argument_list|,
argument|bool with_frame=FALSE
argument_list|,
argument|bool autoDelete_Fields=FALSE
argument_list|)
end_macro

begin_macro
unit|:
name|NCursesForm
argument_list|(
argument|Fields
argument_list|,
argument|lines
argument_list|,
argument|cols
argument_list|,
argument|begin_y
argument_list|,
argument|begin_x
argument_list|,
argument|with_frame
argument_list|,
argument|autoDelete_Fields
argument_list|)
end_macro

begin_block
block|{
if|if
condition|(
name|form
condition|)
name|set_user
argument_list|(
operator|(
name|void
operator|*
operator|)
name|p_UserData
argument_list|)
expr_stmt|;
block|}
end_block

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_expr_stmt
name|virtual
operator|~
name|NCursesUserForm
argument_list|()
block|{   }
expr_stmt|;
end_expr_stmt

begin_decl_stmt
specifier|inline
name|T
modifier|*
name|UserData
argument_list|(
name|void
argument_list|)
decl|const
block|{
return|return
operator|(
name|T
operator|*
operator|)
name|get_user
argument_list|()
return|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_function
specifier|inline
name|virtual
name|void
name|setUserData
parameter_list|(
specifier|const
name|T
modifier|*
name|p_UserData
parameter_list|)
block|{
if|if
condition|(
name|form
condition|)
name|set_user
argument_list|(
operator|(
name|void
operator|*
operator|)
name|p_UserData
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
unit|};
comment|//
end_comment

begin_comment
comment|// -------------------------------------------------------------------------
end_comment

begin_comment
comment|// Builtin Fieldtypes
end_comment

begin_comment
comment|// -------------------------------------------------------------------------
end_comment

begin_comment
comment|//
end_comment

begin_decl_stmt
name|class
name|Alpha_Field
range|:
name|public
name|NCursesFieldType
block|{
name|private
operator|:
name|int
name|min_field_width
block|;
name|void
name|set
argument_list|(
argument|NCursesFormField& f
argument_list|)
block|{
name|OnError
argument_list|(
operator|::
name|set_field_type
argument_list|(
name|f
operator|.
name|get_field
argument_list|()
argument_list|,
name|fieldtype
argument_list|,
name|min_field_width
argument_list|)
argument_list|)
block|;   }
name|public
operator|:
name|Alpha_Field
argument_list|(
argument|int width
argument_list|)
operator|:
name|NCursesFieldType
argument_list|(
name|TYPE_ALPHA
argument_list|)
block|,
name|min_field_width
argument_list|(
argument|width
argument_list|)
block|{   }
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|class
name|Alphanumeric_Field
range|:
name|public
name|NCursesFieldType
block|{
name|private
operator|:
name|int
name|min_field_width
block|;
name|void
name|set
argument_list|(
argument|NCursesFormField& f
argument_list|)
block|{
name|OnError
argument_list|(
operator|::
name|set_field_type
argument_list|(
name|f
operator|.
name|get_field
argument_list|()
argument_list|,
name|fieldtype
argument_list|,
name|min_field_width
argument_list|)
argument_list|)
block|;   }
name|public
operator|:
name|Alphanumeric_Field
argument_list|(
argument|int width
argument_list|)
operator|:
name|NCursesFieldType
argument_list|(
name|TYPE_ALNUM
argument_list|)
block|,
name|min_field_width
argument_list|(
argument|width
argument_list|)
block|{   }
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|class
name|Integer_Field
range|:
name|public
name|NCursesFieldType
block|{
name|private
operator|:
name|int
name|precision
block|;
name|long
name|lower_limit
block|,
name|upper_limit
block|;
name|void
name|set
argument_list|(
argument|NCursesFormField& f
argument_list|)
block|{
name|OnError
argument_list|(
operator|::
name|set_field_type
argument_list|(
name|f
operator|.
name|get_field
argument_list|()
argument_list|,
name|fieldtype
argument_list|,
name|precision
argument_list|,
name|lower_limit
argument_list|,
name|upper_limit
argument_list|)
argument_list|)
block|;   }
name|public
operator|:
name|Integer_Field
argument_list|(
argument|int prec
argument_list|,
argument|long low=
literal|0L
argument_list|,
argument|long high=
literal|0L
argument_list|)
operator|:
name|NCursesFieldType
argument_list|(
name|TYPE_INTEGER
argument_list|)
block|,
name|precision
argument_list|(
name|prec
argument_list|)
block|,
name|lower_limit
argument_list|(
name|low
argument_list|)
block|,
name|upper_limit
argument_list|(
argument|high
argument_list|)
block|{   }
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|class
name|Numeric_Field
range|:
name|public
name|NCursesFieldType
block|{
name|private
operator|:
name|int
name|precision
block|;
name|double
name|lower_limit
block|,
name|upper_limit
block|;
name|void
name|set
argument_list|(
argument|NCursesFormField& f
argument_list|)
block|{
name|OnError
argument_list|(
operator|::
name|set_field_type
argument_list|(
name|f
operator|.
name|get_field
argument_list|()
argument_list|,
name|fieldtype
argument_list|,
name|precision
argument_list|,
name|lower_limit
argument_list|,
name|upper_limit
argument_list|)
argument_list|)
block|;   }
name|public
operator|:
name|Numeric_Field
argument_list|(
argument|int prec
argument_list|,
argument|double low=
literal|0.0
argument_list|,
argument|double high=
literal|0.0
argument_list|)
operator|:
name|NCursesFieldType
argument_list|(
name|TYPE_NUMERIC
argument_list|)
block|,
name|precision
argument_list|(
name|prec
argument_list|)
block|,
name|lower_limit
argument_list|(
name|low
argument_list|)
block|,
name|upper_limit
argument_list|(
argument|high
argument_list|)
block|{   }
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|class
name|Regular_Expression_Field
range|:
name|public
name|NCursesFieldType
block|{
name|private
operator|:
name|char
operator|*
name|regex
block|;
name|void
name|set
argument_list|(
argument|NCursesFormField& f
argument_list|)
block|{
name|OnError
argument_list|(
operator|::
name|set_field_type
argument_list|(
name|f
operator|.
name|get_field
argument_list|()
argument_list|,
name|fieldtype
argument_list|,
name|regex
argument_list|)
argument_list|)
block|;   }
name|public
operator|:
name|Regular_Expression_Field
argument_list|(
specifier|const
name|char
operator|*
name|expr
argument_list|)
operator|:
name|NCursesFieldType
argument_list|(
argument|TYPE_REGEXP
argument_list|)
block|{
name|regex
operator|=
name|new
name|char
index|[
literal|1
operator|+
operator|::
name|strlen
argument_list|(
name|expr
argument_list|)
index|]
block|;
call|(
name|strcpy
call|)
argument_list|(
name|regex
argument_list|,
name|expr
argument_list|)
block|;   }
operator|~
name|Regular_Expression_Field
argument_list|()
block|{
name|delete
index|[]
name|regex
block|;   }
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|class
name|Enumeration_Field
range|:
name|public
name|NCursesFieldType
block|{
name|private
operator|:
name|char
operator|*
operator|*
name|list
block|;
name|int
name|case_sensitive
block|;
name|int
name|non_unique_matches
block|;
name|void
name|set
argument_list|(
argument|NCursesFormField& f
argument_list|)
block|{
name|OnError
argument_list|(
operator|::
name|set_field_type
argument_list|(
name|f
operator|.
name|get_field
argument_list|()
argument_list|,
name|fieldtype
argument_list|,
name|list
argument_list|,
name|case_sensitive
argument_list|,
name|non_unique_matches
argument_list|)
argument_list|)
block|;   }
name|public
operator|:
name|Enumeration_Field
argument_list|(
argument|char* enums[]
argument_list|,
argument|bool case_sens=FALSE
argument_list|,
argument|bool non_unique=FALSE
argument_list|)
operator|:
name|NCursesFieldType
argument_list|(
name|TYPE_ENUM
argument_list|)
block|,
name|list
argument_list|(
name|enums
argument_list|)
block|,
name|case_sensitive
argument_list|(
name|case_sens
condition|?
operator|-
literal|1
else|:
literal|0
argument_list|)
block|,
name|non_unique_matches
argument_list|(
argument|non_unique?-
literal|1
argument|:
literal|0
argument_list|)
block|{   }
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|class
name|IPV4_Address_Field
range|:
name|public
name|NCursesFieldType
block|{
name|private
operator|:
name|void
name|set
argument_list|(
argument|NCursesFormField& f
argument_list|)
block|{
name|OnError
argument_list|(
operator|::
name|set_field_type
argument_list|(
name|f
operator|.
name|get_field
argument_list|()
argument_list|,
name|fieldtype
argument_list|)
argument_list|)
block|;   }
name|public
operator|:
name|IPV4_Address_Field
argument_list|()
operator|:
name|NCursesFieldType
argument_list|(
argument|TYPE_IPV4
argument_list|)
block|{   }
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|//
end_comment

begin_comment
comment|// -------------------------------------------------------------------------
end_comment

begin_comment
comment|// Abstract base class for User-Defined Fieldtypes
end_comment

begin_comment
comment|// -------------------------------------------------------------------------
end_comment

begin_comment
comment|//
end_comment

begin_decl_stmt
name|class
name|UserDefinedFieldType
range|:
name|public
name|NCursesFieldType
block|{
name|friend
name|class
name|UDF_Init
block|;
comment|// Internal helper to set up statics
name|private
operator|:
comment|// For all C++ defined fieldtypes we need only one generic lowlevel
comment|// FIELDTYPE* element.
specifier|static
name|FIELDTYPE
operator|*
name|generic_fieldtype
block|;
name|protected
operator|:
comment|// This are the functions required by the low level libforms functions
comment|// to construct a fieldtype.
specifier|static
name|bool
name|fcheck
argument_list|(
name|FIELD
operator|*
argument_list|,
specifier|const
name|void
operator|*
argument_list|)
block|;
specifier|static
name|bool
name|ccheck
argument_list|(
argument|int c
argument_list|,
argument|const void *
argument_list|)
block|;
specifier|static
name|void
operator|*
name|makearg
argument_list|(
name|va_list
operator|*
argument_list|)
block|;
name|void
name|set
argument_list|(
argument|NCursesFormField& f
argument_list|)
block|{
name|OnError
argument_list|(
operator|::
name|set_field_type
argument_list|(
name|f
operator|.
name|get_field
argument_list|()
argument_list|,
name|fieldtype
argument_list|,
operator|&
name|f
argument_list|)
argument_list|)
block|;   }
name|protected
operator|:
comment|// Redefine this function to do a field validation. The argument
comment|// is a reference to the field you should validate.
name|virtual
name|bool
name|field_check
argument_list|(
name|NCursesFormField
operator|&
name|f
argument_list|)
operator|=
literal|0
block|;
comment|// Redefine this function to do a character validation. The argument
comment|// is the character to be validated.
name|virtual
name|bool
name|char_check
argument_list|(
argument|int c
argument_list|)
operator|=
literal|0
block|;
name|public
operator|:
name|UserDefinedFieldType
argument_list|()
operator|:
name|NCursesFieldType
argument_list|(
argument|generic_fieldtype
argument_list|)
block|{   }
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|//
end_comment

begin_comment
comment|// -------------------------------------------------------------------------
end_comment

begin_comment
comment|// Abstract base class for User-Defined Fieldtypes with Choice functions
end_comment

begin_comment
comment|// -------------------------------------------------------------------------
end_comment

begin_comment
comment|//
end_comment

begin_decl_stmt
name|class
name|UserDefinedFieldType_With_Choice
range|:
name|public
name|UserDefinedFieldType
block|{
name|friend
name|class
name|UDF_Init
block|;
comment|// Internal helper to set up statics
name|private
operator|:
comment|// For all C++ defined fieldtypes with choice functions we need only one
comment|// generic lowlevel FIELDTYPE* element.
specifier|static
name|FIELDTYPE
operator|*
name|generic_fieldtype_with_choice
block|;
comment|// This are the functions required by the low level libforms functions
comment|// to construct a fieldtype with choice functions.
specifier|static
name|bool
name|next_choice
argument_list|(
name|FIELD
operator|*
argument_list|,
specifier|const
name|void
operator|*
argument_list|)
block|;
specifier|static
name|bool
name|prev_choice
argument_list|(
name|FIELD
operator|*
argument_list|,
specifier|const
name|void
operator|*
argument_list|)
block|;
name|protected
operator|:
comment|// Redefine this function to do the retrieval of the next choice value.
comment|// The argument is a reference to the field tobe examined.
name|virtual
name|bool
name|next
argument_list|(
name|NCursesFormField
operator|&
name|f
argument_list|)
operator|=
literal|0
block|;
comment|// Redefine this function to do the retrieval of the previous choice value.
comment|// The argument is a reference to the field tobe examined.
name|virtual
name|bool
name|previous
argument_list|(
name|NCursesFormField
operator|&
name|f
argument_list|)
operator|=
literal|0
block|;
name|public
operator|:
name|UserDefinedFieldType_With_Choice
argument_list|()
block|{
name|fieldtype
operator|=
name|generic_fieldtype_with_choice
block|;   }
block|}
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// _CURSESF_H
end_comment

end_unit

