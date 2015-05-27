begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|///////////////////////////////////////////////////////////////////////////////
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|/// \file       lz_encoder.h
end_comment

begin_comment
comment|/// \brief      LZ in window and match finder API
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|//  Authors:    Igor Pavlov
end_comment

begin_comment
comment|//              Lasse Collin
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
name|LZMA_LZ_ENCODER_H
end_ifndef

begin_define
define|#
directive|define
name|LZMA_LZ_ENCODER_H
end_define

begin_include
include|#
directive|include
file|"common.h"
end_include

begin_comment
comment|/// A table of these is used by the LZ-based encoder to hold
end_comment

begin_comment
comment|/// the length-distance pairs found by the match finder.
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|uint32_t
name|len
decl_stmt|;
name|uint32_t
name|dist
decl_stmt|;
block|}
name|lzma_match
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|lzma_mf_s
name|lzma_mf
typedef|;
end_typedef

begin_struct
struct|struct
name|lzma_mf_s
block|{
comment|///////////////
comment|// In Window //
comment|///////////////
comment|/// Pointer to buffer with data to be compressed
name|uint8_t
modifier|*
name|buffer
decl_stmt|;
comment|/// Total size of the allocated buffer (that is, including all
comment|/// the extra space)
name|uint32_t
name|size
decl_stmt|;
comment|/// Number of bytes that must be kept available in our input history.
comment|/// That is, once keep_size_before bytes have been processed,
comment|/// buffer[read_pos - keep_size_before] is the oldest byte that
comment|/// must be available for reading.
name|uint32_t
name|keep_size_before
decl_stmt|;
comment|/// Number of bytes that must be kept in buffer after read_pos.
comment|/// That is, read_pos<= write_pos - keep_size_after as long as
comment|/// action is LZMA_RUN; when action != LZMA_RUN, read_pos is allowed
comment|/// to reach write_pos so that the last bytes get encoded too.
name|uint32_t
name|keep_size_after
decl_stmt|;
comment|/// Match finders store locations of matches using 32-bit integers.
comment|/// To avoid adjusting several megabytes of integers every time the
comment|/// input window is moved with move_window, we only adjust the
comment|/// offset of the buffer. Thus, buffer[value_in_hash_table - offset]
comment|/// is the byte pointed by value_in_hash_table.
name|uint32_t
name|offset
decl_stmt|;
comment|/// buffer[read_pos] is the next byte to run through the match
comment|/// finder. This is incremented in the match finder once the byte
comment|/// has been processed.
name|uint32_t
name|read_pos
decl_stmt|;
comment|/// Number of bytes that have been ran through the match finder, but
comment|/// which haven't been encoded by the LZ-based encoder yet.
name|uint32_t
name|read_ahead
decl_stmt|;
comment|/// As long as read_pos is less than read_limit, there is enough
comment|/// input available in buffer for at least one encoding loop.
comment|///
comment|/// Because of the stateful API, read_limit may and will get greater
comment|/// than read_pos quite often. This is taken into account when
comment|/// calculating the value for keep_size_after.
name|uint32_t
name|read_limit
decl_stmt|;
comment|/// buffer[write_pos] is the first byte that doesn't contain valid
comment|/// uncompressed data; that is, the next input byte will be copied
comment|/// to buffer[write_pos].
name|uint32_t
name|write_pos
decl_stmt|;
comment|/// Number of bytes not hashed before read_pos. This is needed to
comment|/// restart the match finder after LZMA_SYNC_FLUSH.
name|uint32_t
name|pending
decl_stmt|;
comment|//////////////////
comment|// Match Finder //
comment|//////////////////
comment|/// Find matches. Returns the number of distance-length pairs written
comment|/// to the matches array. This is called only via lzma_mf_find().
name|uint32_t
function_decl|(
modifier|*
name|find
function_decl|)
parameter_list|(
name|lzma_mf
modifier|*
name|mf
parameter_list|,
name|lzma_match
modifier|*
name|matches
parameter_list|)
function_decl|;
comment|/// Skips num bytes. This is like find() but doesn't make the
comment|/// distance-length pairs available, thus being a little faster.
comment|/// This is called only via mf_skip().
name|void
function_decl|(
modifier|*
name|skip
function_decl|)
parameter_list|(
name|lzma_mf
modifier|*
name|mf
parameter_list|,
name|uint32_t
name|num
parameter_list|)
function_decl|;
name|uint32_t
modifier|*
name|hash
decl_stmt|;
name|uint32_t
modifier|*
name|son
decl_stmt|;
name|uint32_t
name|cyclic_pos
decl_stmt|;
name|uint32_t
name|cyclic_size
decl_stmt|;
comment|// Must be dictionary size + 1.
name|uint32_t
name|hash_mask
decl_stmt|;
comment|/// Maximum number of loops in the match finder
name|uint32_t
name|depth
decl_stmt|;
comment|/// Maximum length of a match that the match finder will try to find.
name|uint32_t
name|nice_len
decl_stmt|;
comment|/// Maximum length of a match supported by the LZ-based encoder.
comment|/// If the longest match found by the match finder is nice_len,
comment|/// mf_find() tries to expand it up to match_len_max bytes.
name|uint32_t
name|match_len_max
decl_stmt|;
comment|/// When running out of input, binary tree match finders need to know
comment|/// if it is due to flushing or finishing. The action is used also
comment|/// by the LZ-based encoders themselves.
name|lzma_action
name|action
decl_stmt|;
comment|/// Number of elements in hash[]
name|uint32_t
name|hash_count
decl_stmt|;
comment|/// Number of elements in son[]
name|uint32_t
name|sons_count
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
struct|struct
block|{
comment|/// Extra amount of data to keep available before the "actual"
comment|/// dictionary.
name|size_t
name|before_size
decl_stmt|;
comment|/// Size of the history buffer
name|size_t
name|dict_size
decl_stmt|;
comment|/// Extra amount of data to keep available after the "actual"
comment|/// dictionary.
name|size_t
name|after_size
decl_stmt|;
comment|/// Maximum length of a match that the LZ-based encoder can accept.
comment|/// This is used to extend matches of length nice_len to the
comment|/// maximum possible length.
name|size_t
name|match_len_max
decl_stmt|;
comment|/// Match finder will search matches up to this length.
comment|/// This must be less than or equal to match_len_max.
name|size_t
name|nice_len
decl_stmt|;
comment|/// Type of the match finder to use
name|lzma_match_finder
name|match_finder
decl_stmt|;
comment|/// Maximum search depth
name|uint32_t
name|depth
decl_stmt|;
comment|/// TODO: Comment
specifier|const
name|uint8_t
modifier|*
name|preset_dict
decl_stmt|;
name|uint32_t
name|preset_dict_size
decl_stmt|;
block|}
name|lzma_lz_options
typedef|;
end_typedef

begin_comment
comment|// The total usable buffer space at any moment outside the match finder:
end_comment

begin_comment
comment|// before_size + dict_size + after_size + match_len_max
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// In reality, there's some extra space allocated to prevent the number of
end_comment

begin_comment
comment|// memmove() calls reasonable. The bigger the dict_size is, the bigger
end_comment

begin_comment
comment|// this extra buffer will be since with bigger dictionaries memmove() would
end_comment

begin_comment
comment|// also take longer.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// A single encoder loop in the LZ-based encoder may call the match finder
end_comment

begin_comment
comment|// (mf_find() or mf_skip()) at most after_size times. In other words,
end_comment

begin_comment
comment|// a single encoder loop may increment lzma_mf.read_pos at most after_size
end_comment

begin_comment
comment|// times. Since matches are looked up to
end_comment

begin_comment
comment|// lzma_mf.buffer[lzma_mf.read_pos + match_len_max - 1], the total
end_comment

begin_comment
comment|// amount of extra buffer needed after dict_size becomes
end_comment

begin_comment
comment|// after_size + match_len_max.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// before_size has two uses. The first one is to keep literals available
end_comment

begin_comment
comment|// in cases when the LZ-based encoder has made some read ahead.
end_comment

begin_comment
comment|// TODO: Maybe this could be changed by making the LZ-based encoders to
end_comment

begin_comment
comment|// store the actual literals as they do with length-distance pairs.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Algorithms such as LZMA2 first try to compress a chunk, and then check
end_comment

begin_comment
comment|// if the encoded result is smaller than the uncompressed one. If the chunk
end_comment

begin_comment
comment|// was uncompressible, it is better to store it in uncompressed form in
end_comment

begin_comment
comment|// the output stream. To do this, the whole uncompressed chunk has to be
end_comment

begin_comment
comment|// still available in the history buffer. before_size achieves that.
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
comment|/// Data specific to the LZ-based encoder
name|lzma_coder
modifier|*
name|coder
decl_stmt|;
comment|/// Function to encode from *dict to out[]
name|lzma_ret
function_decl|(
modifier|*
name|code
function_decl|)
parameter_list|(
name|lzma_coder
modifier|*
specifier|restrict
name|coder
parameter_list|,
name|lzma_mf
modifier|*
specifier|restrict
name|mf
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
comment|/// Free allocated resources
name|void
function_decl|(
modifier|*
name|end
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
comment|/// Update the options in the middle of the encoding.
name|lzma_ret
function_decl|(
modifier|*
name|options_update
function_decl|)
parameter_list|(
name|lzma_coder
modifier|*
name|coder
parameter_list|,
specifier|const
name|lzma_filter
modifier|*
name|filter
parameter_list|)
function_decl|;
block|}
name|lzma_lz_encoder
typedef|;
end_typedef

begin_comment
comment|// Basic steps:
end_comment

begin_comment
comment|//  1. Input gets copied into the dictionary.
end_comment

begin_comment
comment|//  2. Data in dictionary gets run through the match finder byte by byte.
end_comment

begin_comment
comment|//  3. The literals and matches are encoded using e.g. LZMA.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// The bytes that have been ran through the match finder, but not encoded yet,
end_comment

begin_comment
comment|// are called `read ahead'.
end_comment

begin_comment
comment|/// Get pointer to the first byte not ran through the match finder
end_comment

begin_function
specifier|static
specifier|inline
specifier|const
name|uint8_t
modifier|*
name|mf_ptr
parameter_list|(
specifier|const
name|lzma_mf
modifier|*
name|mf
parameter_list|)
block|{
return|return
name|mf
operator|->
name|buffer
operator|+
name|mf
operator|->
name|read_pos
return|;
block|}
end_function

begin_comment
comment|/// Get the number of bytes that haven't been ran through the match finder yet.
end_comment

begin_function
specifier|static
specifier|inline
name|uint32_t
name|mf_avail
parameter_list|(
specifier|const
name|lzma_mf
modifier|*
name|mf
parameter_list|)
block|{
return|return
name|mf
operator|->
name|write_pos
operator|-
name|mf
operator|->
name|read_pos
return|;
block|}
end_function

begin_comment
comment|/// Get the number of bytes that haven't been encoded yet (some of these
end_comment

begin_comment
comment|/// bytes may have been ran through the match finder though).
end_comment

begin_function
specifier|static
specifier|inline
name|uint32_t
name|mf_unencoded
parameter_list|(
specifier|const
name|lzma_mf
modifier|*
name|mf
parameter_list|)
block|{
return|return
name|mf
operator|->
name|write_pos
operator|-
name|mf
operator|->
name|read_pos
operator|+
name|mf
operator|->
name|read_ahead
return|;
block|}
end_function

begin_comment
comment|/// Calculate the absolute offset from the beginning of the most recent
end_comment

begin_comment
comment|/// dictionary reset. Only the lowest four bits are important, so there's no
end_comment

begin_comment
comment|/// problem that we don't know the 64-bit size of the data encoded so far.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// NOTE: When moving the input window, we need to do it so that the lowest
end_comment

begin_comment
comment|/// bits of dict->read_pos are not modified to keep this macro working
end_comment

begin_comment
comment|/// as intended.
end_comment

begin_function
specifier|static
specifier|inline
name|uint32_t
name|mf_position
parameter_list|(
specifier|const
name|lzma_mf
modifier|*
name|mf
parameter_list|)
block|{
return|return
name|mf
operator|->
name|read_pos
operator|-
name|mf
operator|->
name|read_ahead
return|;
block|}
end_function

begin_comment
comment|/// Since everything else begins with mf_, use it also for lzma_mf_find().
end_comment

begin_define
define|#
directive|define
name|mf_find
value|lzma_mf_find
end_define

begin_comment
comment|/// Skip the given number of bytes. This is used when a good match was found.
end_comment

begin_comment
comment|/// For example, if mf_find() finds a match of 200 bytes long, the first byte
end_comment

begin_comment
comment|/// of that match was already consumed by mf_find(), and the rest 199 bytes
end_comment

begin_comment
comment|/// have to be skipped with mf_skip(mf, 199).
end_comment

begin_function
specifier|static
specifier|inline
name|void
name|mf_skip
parameter_list|(
name|lzma_mf
modifier|*
name|mf
parameter_list|,
name|uint32_t
name|amount
parameter_list|)
block|{
if|if
condition|(
name|amount
operator|!=
literal|0
condition|)
block|{
name|mf
operator|->
name|skip
argument_list|(
name|mf
argument_list|,
name|amount
argument_list|)
expr_stmt|;
name|mf
operator|->
name|read_ahead
operator|+=
name|amount
expr_stmt|;
block|}
block|}
end_function

begin_comment
comment|/// Copies at most *left number of bytes from the history buffer
end_comment

begin_comment
comment|/// to out[]. This is needed by LZMA2 to encode uncompressed chunks.
end_comment

begin_function
specifier|static
specifier|inline
name|void
name|mf_read
parameter_list|(
name|lzma_mf
modifier|*
name|mf
parameter_list|,
name|uint8_t
modifier|*
name|out
parameter_list|,
name|size_t
modifier|*
name|out_pos
parameter_list|,
name|size_t
name|out_size
parameter_list|,
name|size_t
modifier|*
name|left
parameter_list|)
block|{
specifier|const
name|size_t
name|out_avail
init|=
name|out_size
operator|-
operator|*
name|out_pos
decl_stmt|;
specifier|const
name|size_t
name|copy_size
init|=
name|my_min
argument_list|(
name|out_avail
argument_list|,
operator|*
name|left
argument_list|)
decl_stmt|;
name|assert
argument_list|(
name|mf
operator|->
name|read_ahead
operator|==
literal|0
argument_list|)
expr_stmt|;
name|assert
argument_list|(
name|mf
operator|->
name|read_pos
operator|>=
operator|*
name|left
argument_list|)
expr_stmt|;
name|memcpy
argument_list|(
name|out
operator|+
operator|*
name|out_pos
argument_list|,
name|mf
operator|->
name|buffer
operator|+
name|mf
operator|->
name|read_pos
operator|-
operator|*
name|left
argument_list|,
name|copy_size
argument_list|)
expr_stmt|;
operator|*
name|out_pos
operator|+=
name|copy_size
expr_stmt|;
operator|*
name|left
operator|-=
name|copy_size
expr_stmt|;
return|return;
block|}
end_function

begin_function_decl
specifier|extern
name|lzma_ret
name|lzma_lz_encoder_init
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
parameter_list|,
name|lzma_ret
function_decl|(
modifier|*
name|lz_init
function_decl|)
parameter_list|(
name|lzma_lz_encoder
modifier|*
name|lz
parameter_list|,
specifier|const
name|lzma_allocator
modifier|*
name|allocator
parameter_list|,
specifier|const
name|void
modifier|*
name|options
parameter_list|,
name|lzma_lz_options
modifier|*
name|lz_options
parameter_list|)
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|uint64_t
name|lzma_lz_encoder_memusage
parameter_list|(
specifier|const
name|lzma_lz_options
modifier|*
name|lz_options
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|// These are only for LZ encoder's internal use.
end_comment

begin_function_decl
specifier|extern
name|uint32_t
name|lzma_mf_find
parameter_list|(
name|lzma_mf
modifier|*
name|mf
parameter_list|,
name|uint32_t
modifier|*
name|count
parameter_list|,
name|lzma_match
modifier|*
name|matches
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|uint32_t
name|lzma_mf_hc3_find
parameter_list|(
name|lzma_mf
modifier|*
name|dict
parameter_list|,
name|lzma_match
modifier|*
name|matches
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|lzma_mf_hc3_skip
parameter_list|(
name|lzma_mf
modifier|*
name|dict
parameter_list|,
name|uint32_t
name|amount
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|uint32_t
name|lzma_mf_hc4_find
parameter_list|(
name|lzma_mf
modifier|*
name|dict
parameter_list|,
name|lzma_match
modifier|*
name|matches
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|lzma_mf_hc4_skip
parameter_list|(
name|lzma_mf
modifier|*
name|dict
parameter_list|,
name|uint32_t
name|amount
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|uint32_t
name|lzma_mf_bt2_find
parameter_list|(
name|lzma_mf
modifier|*
name|dict
parameter_list|,
name|lzma_match
modifier|*
name|matches
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|lzma_mf_bt2_skip
parameter_list|(
name|lzma_mf
modifier|*
name|dict
parameter_list|,
name|uint32_t
name|amount
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|uint32_t
name|lzma_mf_bt3_find
parameter_list|(
name|lzma_mf
modifier|*
name|dict
parameter_list|,
name|lzma_match
modifier|*
name|matches
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|lzma_mf_bt3_skip
parameter_list|(
name|lzma_mf
modifier|*
name|dict
parameter_list|,
name|uint32_t
name|amount
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|uint32_t
name|lzma_mf_bt4_find
parameter_list|(
name|lzma_mf
modifier|*
name|dict
parameter_list|,
name|lzma_match
modifier|*
name|matches
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|lzma_mf_bt4_skip
parameter_list|(
name|lzma_mf
modifier|*
name|dict
parameter_list|,
name|uint32_t
name|amount
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

end_unit

