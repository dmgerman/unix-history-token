begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- dfsan_interface.h -------------------------------------------------===//
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

begin_comment
comment|//
end_comment

begin_comment
comment|// This file is a part of DataFlowSanitizer.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Public interface header.
end_comment

begin_comment
comment|//===----------------------------------------------------------------------===//
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|DFSAN_INTERFACE_H
end_ifndef

begin_define
define|#
directive|define
name|DFSAN_INTERFACE_H
end_define

begin_include
include|#
directive|include
file|<stddef.h>
end_include

begin_include
include|#
directive|include
file|<stdint.h>
end_include

begin_include
include|#
directive|include
file|<sanitizer/common_interface_defs.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|__cplusplus
end_ifdef

begin_extern
extern|extern
literal|"C"
block|{
endif|#
directive|endif
typedef|typedef
name|uint16_t
name|dfsan_label
typedef|;
comment|/// Stores information associated with a specific label identifier.  A label
comment|/// may be a base label created using dfsan_create_label, with associated
comment|/// text description and user data, or an automatically created union label,
comment|/// which represents the union of two label identifiers (which may themselves
comment|/// be base or union labels).
struct|struct
name|dfsan_label_info
block|{
comment|// Fields for union labels, set to 0 for base labels.
name|dfsan_label
name|l1
decl_stmt|;
name|dfsan_label
name|l2
decl_stmt|;
comment|// Fields for base labels.
specifier|const
name|char
modifier|*
name|desc
decl_stmt|;
name|void
modifier|*
name|userdata
decl_stmt|;
block|}
struct|;
comment|/// Signature of the callback argument to dfsan_set_write_callback().
typedef|typedef
name|void
function_decl|(
modifier|*
name|dfsan_write_callback_t
function_decl|)
parameter_list|(
name|int
name|fd
parameter_list|,
specifier|const
name|void
modifier|*
name|buf
parameter_list|,
name|size_t
name|count
parameter_list|)
function_decl|;
comment|/// Computes the union of \c l1 and \c l2, possibly creating a union label in
comment|/// the process.
name|dfsan_label
name|dfsan_union
parameter_list|(
name|dfsan_label
name|l1
parameter_list|,
name|dfsan_label
name|l2
parameter_list|)
function_decl|;
comment|/// Creates and returns a base label with the given description and user data.
name|dfsan_label
name|dfsan_create_label
parameter_list|(
specifier|const
name|char
modifier|*
name|desc
parameter_list|,
name|void
modifier|*
name|userdata
parameter_list|)
function_decl|;
comment|/// Sets the label for each address in [addr,addr+size) to \c label.
name|void
name|dfsan_set_label
parameter_list|(
name|dfsan_label
name|label
parameter_list|,
name|void
modifier|*
name|addr
parameter_list|,
name|size_t
name|size
parameter_list|)
function_decl|;
comment|/// Sets the label for each address in [addr,addr+size) to the union of the
comment|/// current label for that address and \c label.
name|void
name|dfsan_add_label
parameter_list|(
name|dfsan_label
name|label
parameter_list|,
name|void
modifier|*
name|addr
parameter_list|,
name|size_t
name|size
parameter_list|)
function_decl|;
comment|/// Retrieves the label associated with the given data.
comment|///
comment|/// The type of 'data' is arbitrary.  The function accepts a value of any type,
comment|/// which can be truncated or extended (implicitly or explicitly) as necessary.
comment|/// The truncation/extension operations will preserve the label of the original
comment|/// value.
name|dfsan_label
name|dfsan_get_label
parameter_list|(
name|long
name|data
parameter_list|)
function_decl|;
comment|/// Retrieves the label associated with the data at the given address.
name|dfsan_label
name|dfsan_read_label
parameter_list|(
specifier|const
name|void
modifier|*
name|addr
parameter_list|,
name|size_t
name|size
parameter_list|)
function_decl|;
comment|/// Retrieves a pointer to the dfsan_label_info struct for the given label.
specifier|const
name|struct
name|dfsan_label_info
modifier|*
name|dfsan_get_label_info
parameter_list|(
name|dfsan_label
name|label
parameter_list|)
function_decl|;
comment|/// Returns whether the given label label contains the label elem.
name|int
name|dfsan_has_label
parameter_list|(
name|dfsan_label
name|label
parameter_list|,
name|dfsan_label
name|elem
parameter_list|)
function_decl|;
comment|/// If the given label label contains a label with the description desc, returns
comment|/// that label, else returns 0.
name|dfsan_label
name|dfsan_has_label_with_desc
parameter_list|(
name|dfsan_label
name|label
parameter_list|,
specifier|const
name|char
modifier|*
name|desc
parameter_list|)
function_decl|;
comment|/// Returns the number of labels allocated.
name|size_t
name|dfsan_get_label_count
parameter_list|(
name|void
parameter_list|)
function_decl|;
comment|/// Sets a callback to be invoked on calls to write().  The callback is invoked
comment|/// before the write is done.  The write is not guaranteed to succeed when the
comment|/// callback executes.  Pass in NULL to remove any callback.
name|void
name|dfsan_set_write_callback
parameter_list|(
name|dfsan_write_callback_t
name|labeled_write_callback
parameter_list|)
function_decl|;
comment|/// Writes the labels currently used by the program to the given file
comment|/// descriptor. The lines of the output have the following format:
comment|///
comment|///<label><parent label 1><parent label 2><label description if any>
name|void
name|dfsan_dump_labels
parameter_list|(
name|int
name|fd
parameter_list|)
function_decl|;
ifdef|#
directive|ifdef
name|__cplusplus
block|}
end_extern

begin_comment
comment|// extern "C"
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|T
operator|>
name|void
name|dfsan_set_label
argument_list|(
argument|dfsan_label label
argument_list|,
argument|T&data
argument_list|)
block|{
comment|// NOLINT
name|dfsan_set_label
argument_list|(
name|label
argument_list|,
operator|(
name|void
operator|*
operator|)
operator|&
name|data
argument_list|,
sizeof|sizeof
argument_list|(
name|T
argument_list|)
argument_list|)
block|; }
end_expr_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// DFSAN_INTERFACE_H
end_comment

end_unit

