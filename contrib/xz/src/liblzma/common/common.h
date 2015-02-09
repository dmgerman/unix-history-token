begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|///////////////////////////////////////////////////////////////////////////////
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|/// \file       common.h
end_comment

begin_comment
comment|/// \brief      Definitions common to the whole liblzma library
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//  Author:     Lasse Collin
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//  This file has been put into the public domain.
end_comment

begin_comment
comment|//  You can do whatever you want with this file.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|///////////////////////////////////////////////////////////////////////////////
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|LZMA_COMMON_H
end_ifndef

begin_define
define|#
directive|define
name|LZMA_COMMON_H
end_define

begin_include
include|#
directive|include
file|"sysdefs.h"
end_include

begin_include
include|#
directive|include
file|"mythread.h"
end_include

begin_include
include|#
directive|include
file|"tuklib_integer.h"
end_include

begin_if
if|#
directive|if
name|defined
argument_list|(
name|_WIN32
argument_list|)
operator|||
name|defined
argument_list|(
name|__CYGWIN__
argument_list|)
end_if

begin_ifdef
ifdef|#
directive|ifdef
name|DLL_EXPORT
end_ifdef

begin_define
define|#
directive|define
name|LZMA_API_EXPORT
value|__declspec(dllexport)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|LZMA_API_EXPORT
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// Don't use ifdef or defined() below.
end_comment

begin_elif
elif|#
directive|elif
name|HAVE_VISIBILITY
end_elif

begin_define
define|#
directive|define
name|LZMA_API_EXPORT
value|__attribute__((__visibility__("default")))
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|LZMA_API_EXPORT
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|LZMA_API
parameter_list|(
name|type
parameter_list|)
value|LZMA_API_EXPORT type LZMA_API_CALL
end_define

begin_include
include|#
directive|include
file|"lzma.h"
end_include

begin_comment
comment|// These allow helping the compiler in some often-executed branches, whose
end_comment

begin_comment
comment|// result is almost always the same.
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__GNUC__
end_ifdef

begin_define
define|#
directive|define
name|likely
parameter_list|(
name|expr
parameter_list|)
value|__builtin_expect(expr, true)
end_define

begin_define
define|#
directive|define
name|unlikely
parameter_list|(
name|expr
parameter_list|)
value|__builtin_expect(expr, false)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|likely
parameter_list|(
name|expr
parameter_list|)
value|(expr)
end_define

begin_define
define|#
directive|define
name|unlikely
parameter_list|(
name|expr
parameter_list|)
value|(expr)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/// Size of temporary buffers needed in some filters
end_comment

begin_define
define|#
directive|define
name|LZMA_BUFFER_SIZE
value|4096
end_define

begin_comment
comment|/// Maximum number of worker threads within one multithreaded component.
end_comment

begin_comment
comment|/// The limit exists solely to make it simpler to prevent integer overflows
end_comment

begin_comment
comment|/// when allocating structures etc. This should be big enough for now...
end_comment

begin_comment
comment|/// the code won't scale anywhere close to this number anyway.
end_comment

begin_define
define|#
directive|define
name|LZMA_THREADS_MAX
value|16384
end_define

begin_comment
comment|/// Starting value for memory usage estimates. Instead of calculating size
end_comment

begin_comment
comment|/// of _every_ structure and taking into account malloc() overhead etc., we
end_comment

begin_comment
comment|/// add a base size to all memory usage estimates. It's not very accurate
end_comment

begin_comment
comment|/// but should be easily good enough.
end_comment

begin_define
define|#
directive|define
name|LZMA_MEMUSAGE_BASE
value|(UINT64_C(1)<< 15)
end_define

begin_comment
comment|/// Start of internal Filter ID space. These IDs must never be used
end_comment

begin_comment
comment|/// in Streams.
end_comment

begin_define
define|#
directive|define
name|LZMA_FILTER_RESERVED_START
value|(LZMA_VLI_C(1)<< 62)
end_define

begin_comment
comment|/// Supported flags that can be passed to lzma_stream_decoder()
end_comment

begin_comment
comment|/// or lzma_auto_decoder().
end_comment

begin_define
define|#
directive|define
name|LZMA_SUPPORTED_FLAGS
define|\
value|( LZMA_TELL_NO_CHECK \ 	| LZMA_TELL_UNSUPPORTED_CHECK \ 	| LZMA_TELL_ANY_CHECK \ 	| LZMA_IGNORE_CHECK \ 	| LZMA_CONCATENATED )
end_define

begin_comment
comment|/// Largest valid lzma_action value as unsigned integer.
end_comment

begin_define
define|#
directive|define
name|LZMA_ACTION_MAX
value|((unsigned int)(LZMA_FULL_BARRIER))
end_define

begin_comment
comment|/// Special return value (lzma_ret) to indicate that a timeout was reached
end_comment

begin_comment
comment|/// and lzma_code() must not return LZMA_BUF_ERROR. This is converted to
end_comment

begin_comment
comment|/// LZMA_OK in lzma_code(). This is not in the lzma_ret enumeration because
end_comment

begin_comment
comment|/// there's no need to have it in the public API.
end_comment

begin_define
define|#
directive|define
name|LZMA_TIMED_OUT
value|32
end_define

begin_comment
comment|/// Type of encoder/decoder specific data; the actual structure is defined
end_comment

begin_comment
comment|/// differently in different coders.
end_comment

begin_typedef
typedef|typedef
name|struct
name|lzma_coder_s
name|lzma_coder
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|lzma_next_coder_s
name|lzma_next_coder
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|lzma_filter_info_s
name|lzma_filter_info
typedef|;
end_typedef

begin_comment
comment|/// Type of a function used to initialize a filter encoder or decoder
end_comment

begin_typedef
typedef|typedef
name|lzma_ret
function_decl|(
modifier|*
name|lzma_init_function
function_decl|)
parameter_list|(
name|lzma_next_coder
modifier|*
name|next
parameter_list|,
specifier|const
name|lzma_allocator
modifier|*
name|allocator
parameter_list|,
specifier|const
name|lzma_filter_info
modifier|*
name|filters
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/// Type of a function to do some kind of coding work (filters, Stream,
end_comment

begin_comment
comment|/// Block encoders/decoders etc.). Some special coders use don't use both
end_comment

begin_comment
comment|/// input and output buffers, but for simplicity they still use this same
end_comment

begin_comment
comment|/// function prototype.
end_comment

begin_typedef
typedef|typedef
name|lzma_ret
function_decl|(
modifier|*
name|lzma_code_function
function_decl|)
parameter_list|(
name|lzma_coder
modifier|*
name|coder
parameter_list|,
specifier|const
name|lzma_allocator
modifier|*
name|allocator
parameter_list|,
specifier|const
name|uint8_t
modifier|*
specifier|restrict
name|in
parameter_list|,
name|size_t
modifier|*
specifier|restrict
name|in_pos
parameter_list|,
name|size_t
name|in_size
parameter_list|,
name|uint8_t
modifier|*
specifier|restrict
name|out
parameter_list|,
name|size_t
modifier|*
specifier|restrict
name|out_pos
parameter_list|,
name|size_t
name|out_size
parameter_list|,
name|lzma_action
name|action
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/// Type of a function to free the memory allocated for the coder
end_comment

begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|*
name|lzma_end_function
function_decl|)
parameter_list|(
name|lzma_coder
modifier|*
name|coder
parameter_list|,
specifier|const
name|lzma_allocator
modifier|*
name|allocator
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/// Raw coder validates and converts an array of lzma_filter structures to
end_comment

begin_comment
comment|/// an array of lzma_filter_info structures. This array is used with
end_comment

begin_comment
comment|/// lzma_next_filter_init to initialize the filter chain.
end_comment

begin_struct
struct|struct
name|lzma_filter_info_s
block|{
comment|/// Filter ID. This is used only by the encoder
comment|/// with lzma_filters_update().
name|lzma_vli
name|id
decl_stmt|;
comment|/// Pointer to function used to initialize the filter.
comment|/// This is NULL to indicate end of array.
name|lzma_init_function
name|init
decl_stmt|;
comment|/// Pointer to filter's options structure
name|void
modifier|*
name|options
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/// Hold data and function pointers of the next filter in the chain.
end_comment

begin_struct
struct|struct
name|lzma_next_coder_s
block|{
comment|/// Pointer to coder-specific data
name|lzma_coder
modifier|*
name|coder
decl_stmt|;
comment|/// Filter ID. This is LZMA_VLI_UNKNOWN when this structure doesn't
comment|/// point to a filter coder.
name|lzma_vli
name|id
decl_stmt|;
comment|/// "Pointer" to init function. This is never called here.
comment|/// We need only to detect if we are initializing a coder
comment|/// that was allocated earlier. See lzma_next_coder_init and
comment|/// lzma_next_strm_init macros in this file.
name|uintptr_t
name|init
decl_stmt|;
comment|/// Pointer to function to do the actual coding
name|lzma_code_function
name|code
decl_stmt|;
comment|/// Pointer to function to free lzma_next_coder.coder. This can
comment|/// be NULL; in that case, lzma_free is called to free
comment|/// lzma_next_coder.coder.
name|lzma_end_function
name|end
decl_stmt|;
comment|/// Pointer to a function to get progress information. If this is NULL,
comment|/// lzma_stream.total_in and .total_out are used instead.
name|void
function_decl|(
modifier|*
name|get_progress
function_decl|)
parameter_list|(
name|lzma_coder
modifier|*
name|coder
parameter_list|,
name|uint64_t
modifier|*
name|progress_in
parameter_list|,
name|uint64_t
modifier|*
name|progress_out
parameter_list|)
function_decl|;
comment|/// Pointer to function to return the type of the integrity check.
comment|/// Most coders won't support this.
name|lzma_check
function_decl|(
modifier|*
name|get_check
function_decl|)
parameter_list|(
specifier|const
name|lzma_coder
modifier|*
name|coder
parameter_list|)
function_decl|;
comment|/// Pointer to function to get and/or change the memory usage limit.
comment|/// If new_memlimit == 0, the limit is not changed.
name|lzma_ret
function_decl|(
modifier|*
name|memconfig
function_decl|)
parameter_list|(
name|lzma_coder
modifier|*
name|coder
parameter_list|,
name|uint64_t
modifier|*
name|memusage
parameter_list|,
name|uint64_t
modifier|*
name|old_memlimit
parameter_list|,
name|uint64_t
name|new_memlimit
parameter_list|)
function_decl|;
comment|/// Update the filter-specific options or the whole filter chain
comment|/// in the encoder.
name|lzma_ret
function_decl|(
modifier|*
name|update
function_decl|)
parameter_list|(
name|lzma_coder
modifier|*
name|coder
parameter_list|,
specifier|const
name|lzma_allocator
modifier|*
name|allocator
parameter_list|,
specifier|const
name|lzma_filter
modifier|*
name|filters
parameter_list|,
specifier|const
name|lzma_filter
modifier|*
name|reversed_filters
parameter_list|)
function_decl|;
block|}
struct|;
end_struct

begin_comment
comment|/// Macro to initialize lzma_next_coder structure
end_comment

begin_define
define|#
directive|define
name|LZMA_NEXT_CODER_INIT
define|\
value|(lzma_next_coder){ \ 		.coder = NULL, \ 		.init = (uintptr_t)(NULL), \ 		.id = LZMA_VLI_UNKNOWN, \ 		.code = NULL, \ 		.end = NULL, \ 		.get_progress = NULL, \ 		.get_check = NULL, \ 		.memconfig = NULL, \ 		.update = NULL, \ 	}
end_define

begin_comment
comment|/// Internal data for lzma_strm_init, lzma_code, and lzma_end. A pointer to
end_comment

begin_comment
comment|/// this is stored in lzma_stream.
end_comment

begin_struct
struct|struct
name|lzma_internal_s
block|{
comment|/// The actual coder that should do something useful
name|lzma_next_coder
name|next
decl_stmt|;
comment|/// Track the state of the coder. This is used to validate arguments
comment|/// so that the actual coders can rely on e.g. that LZMA_SYNC_FLUSH
comment|/// is used on every call to lzma_code until next.code has returned
comment|/// LZMA_STREAM_END.
enum|enum
block|{
name|ISEQ_RUN
block|,
name|ISEQ_SYNC_FLUSH
block|,
name|ISEQ_FULL_FLUSH
block|,
name|ISEQ_FINISH
block|,
name|ISEQ_FULL_BARRIER
block|,
name|ISEQ_END
block|,
name|ISEQ_ERROR
block|, 	}
name|sequence
enum|;
comment|/// A copy of lzma_stream avail_in. This is used to verify that the
comment|/// amount of input doesn't change once e.g. LZMA_FINISH has been
comment|/// used.
name|size_t
name|avail_in
decl_stmt|;
comment|/// Indicates which lzma_action values are allowed by next.code.
name|bool
name|supported_actions
index|[
name|LZMA_ACTION_MAX
operator|+
literal|1
index|]
decl_stmt|;
comment|/// If true, lzma_code will return LZMA_BUF_ERROR if no progress was
comment|/// made (no input consumed and no output produced by next.code).
name|bool
name|allow_buf_error
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/// Allocates memory
end_comment

begin_function_decl
specifier|extern
name|void
modifier|*
name|lzma_alloc
parameter_list|(
name|size_t
name|size
parameter_list|,
specifier|const
name|lzma_allocator
modifier|*
name|allocator
parameter_list|)
function_decl|lzma_attribute
parameter_list|(
function_decl|(__malloc__
end_function_decl

begin_expr_stmt
unit|))
name|lzma_attr_alloc_size
argument_list|(
literal|1
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// Allocates memory and zeroes it (like calloc()). This can be faster
end_comment

begin_comment
comment|/// than lzma_alloc() + memzero() while being backward compatible with
end_comment

begin_comment
comment|/// custom allocators.
end_comment

begin_decl_stmt
specifier|extern
name|void
modifier|*
name|lzma_attribute
argument_list|(
operator|(
name|__malloc__
operator|)
argument_list|)
name|lzma_attr_alloc_size
argument_list|(
literal|1
argument_list|)
name|lzma_alloc_zero
argument_list|(
name|size_t
name|size
argument_list|,
specifier|const
name|lzma_allocator
operator|*
name|allocator
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// Frees memory
end_comment

begin_function_decl
specifier|extern
name|void
name|lzma_free
parameter_list|(
name|void
modifier|*
name|ptr
parameter_list|,
specifier|const
name|lzma_allocator
modifier|*
name|allocator
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// Allocates strm->internal if it is NULL, and initializes *strm and
end_comment

begin_comment
comment|/// strm->internal. This function is only called via lzma_next_strm_init macro.
end_comment

begin_function_decl
specifier|extern
name|lzma_ret
name|lzma_strm_init
parameter_list|(
name|lzma_stream
modifier|*
name|strm
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// Initializes the next filter in the chain, if any. This takes care of
end_comment

begin_comment
comment|/// freeing the memory of previously initialized filter if it is different
end_comment

begin_comment
comment|/// than the filter being initialized now. This way the actual filter
end_comment

begin_comment
comment|/// initialization functions don't need to use lzma_next_coder_init macro.
end_comment

begin_function_decl
specifier|extern
name|lzma_ret
name|lzma_next_filter_init
parameter_list|(
name|lzma_next_coder
modifier|*
name|next
parameter_list|,
specifier|const
name|lzma_allocator
modifier|*
name|allocator
parameter_list|,
specifier|const
name|lzma_filter_info
modifier|*
name|filters
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// Update the next filter in the chain, if any. This checks that
end_comment

begin_comment
comment|/// the application is not trying to change the Filter IDs.
end_comment

begin_function_decl
specifier|extern
name|lzma_ret
name|lzma_next_filter_update
parameter_list|(
name|lzma_next_coder
modifier|*
name|next
parameter_list|,
specifier|const
name|lzma_allocator
modifier|*
name|allocator
parameter_list|,
specifier|const
name|lzma_filter
modifier|*
name|reversed_filters
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// Frees the memory allocated for next->coder either using next->end or,
end_comment

begin_comment
comment|/// if next->end is NULL, using lzma_free.
end_comment

begin_function_decl
specifier|extern
name|void
name|lzma_next_end
parameter_list|(
name|lzma_next_coder
modifier|*
name|next
parameter_list|,
specifier|const
name|lzma_allocator
modifier|*
name|allocator
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// Copy as much data as possible from in[] to out[] and update *in_pos
end_comment

begin_comment
comment|/// and *out_pos accordingly. Returns the number of bytes copied.
end_comment

begin_function_decl
specifier|extern
name|size_t
name|lzma_bufcpy
parameter_list|(
specifier|const
name|uint8_t
modifier|*
specifier|restrict
name|in
parameter_list|,
name|size_t
modifier|*
specifier|restrict
name|in_pos
parameter_list|,
name|size_t
name|in_size
parameter_list|,
name|uint8_t
modifier|*
specifier|restrict
name|out
parameter_list|,
name|size_t
modifier|*
specifier|restrict
name|out_pos
parameter_list|,
name|size_t
name|out_size
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// \brief      Return if expression doesn't evaluate to LZMA_OK
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// There are several situations where we want to return immediately
end_comment

begin_comment
comment|/// with the value of expr if it isn't LZMA_OK. This macro shortens
end_comment

begin_comment
comment|/// the code a little.
end_comment

begin_define
define|#
directive|define
name|return_if_error
parameter_list|(
name|expr
parameter_list|)
define|\
value|do { \ 	const lzma_ret ret_ = (expr); \ 	if (ret_ != LZMA_OK) \ 		return ret_; \ } while (0)
end_define

begin_comment
comment|/// If next isn't already initialized, free the previous coder. Then mark
end_comment

begin_comment
comment|/// that next is _possibly_ initialized for the coder using this macro.
end_comment

begin_comment
comment|/// "Possibly" means that if e.g. allocation of next->coder fails, the
end_comment

begin_comment
comment|/// structure isn't actually initialized for this coder, but leaving
end_comment

begin_comment
comment|/// next->init to func is still OK.
end_comment

begin_define
define|#
directive|define
name|lzma_next_coder_init
parameter_list|(
name|func
parameter_list|,
name|next
parameter_list|,
name|allocator
parameter_list|)
define|\
value|do { \ 	if ((uintptr_t)(func) != (next)->init) \ 		lzma_next_end(next, allocator); \ 	(next)->init = (uintptr_t)(func); \ } while (0)
end_define

begin_comment
comment|/// Initializes lzma_strm and calls func() to initialize strm->internal->next.
end_comment

begin_comment
comment|/// (The function being called will use lzma_next_coder_init()). If
end_comment

begin_comment
comment|/// initialization fails, memory that wasn't freed by func() is freed
end_comment

begin_comment
comment|/// along strm->internal.
end_comment

begin_define
define|#
directive|define
name|lzma_next_strm_init
parameter_list|(
name|func
parameter_list|,
name|strm
parameter_list|,
modifier|...
parameter_list|)
define|\
value|do { \ 	return_if_error(lzma_strm_init(strm)); \ 	const lzma_ret ret_ = func(&(strm)->internal->next, \ 			(strm)->allocator, __VA_ARGS__); \ 	if (ret_ != LZMA_OK) { \ 		lzma_end(strm); \ 		return ret_; \ 	} \ } while (0)
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

