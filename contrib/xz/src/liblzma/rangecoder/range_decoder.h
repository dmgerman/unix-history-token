begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|///////////////////////////////////////////////////////////////////////////////
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|/// \file       range_decoder.h
end_comment

begin_comment
comment|/// \brief      Range Decoder
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
name|LZMA_RANGE_DECODER_H
end_ifndef

begin_define
define|#
directive|define
name|LZMA_RANGE_DECODER_H
end_define

begin_include
include|#
directive|include
file|"range_common.h"
end_include

begin_typedef
typedef|typedef
struct|struct
block|{
name|uint32_t
name|range
decl_stmt|;
name|uint32_t
name|code
decl_stmt|;
name|uint32_t
name|init_bytes_left
decl_stmt|;
block|}
name|lzma_range_decoder
typedef|;
end_typedef

begin_comment
comment|/// Reads the first five bytes to initialize the range decoder.
end_comment

begin_function
specifier|static
specifier|inline
name|lzma_ret
name|rc_read_init
parameter_list|(
name|lzma_range_decoder
modifier|*
name|rc
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
parameter_list|)
block|{
while|while
condition|(
name|rc
operator|->
name|init_bytes_left
operator|>
literal|0
condition|)
block|{
if|if
condition|(
operator|*
name|in_pos
operator|==
name|in_size
condition|)
return|return
name|LZMA_OK
return|;
comment|// The first byte is always 0x00. It could have been omitted
comment|// in LZMA2 but it wasn't, so one byte is wasted in every
comment|// LZMA2 chunk.
if|if
condition|(
name|rc
operator|->
name|init_bytes_left
operator|==
literal|5
operator|&&
name|in
index|[
operator|*
name|in_pos
index|]
operator|!=
literal|0x00
condition|)
return|return
name|LZMA_DATA_ERROR
return|;
name|rc
operator|->
name|code
operator|=
operator|(
name|rc
operator|->
name|code
operator|<<
literal|8
operator|)
operator||
name|in
index|[
operator|*
name|in_pos
index|]
expr_stmt|;
operator|++
operator|*
name|in_pos
expr_stmt|;
operator|--
name|rc
operator|->
name|init_bytes_left
expr_stmt|;
block|}
return|return
name|LZMA_STREAM_END
return|;
block|}
end_function

begin_comment
comment|/// Makes local copies of range decoder and *in_pos variables. Doing this
end_comment

begin_comment
comment|/// improves speed significantly. The range decoder macros expect also
end_comment

begin_comment
comment|/// variables `in' and `in_size' to be defined.
end_comment

begin_define
define|#
directive|define
name|rc_to_local
parameter_list|(
name|range_decoder
parameter_list|,
name|in_pos
parameter_list|)
define|\
value|lzma_range_decoder rc = range_decoder; \ 	size_t rc_in_pos = (in_pos); \ 	uint32_t rc_bound
end_define

begin_comment
comment|/// Stores the local copes back to the range decoder structure.
end_comment

begin_define
define|#
directive|define
name|rc_from_local
parameter_list|(
name|range_decoder
parameter_list|,
name|in_pos
parameter_list|)
define|\
value|do { \ 	range_decoder = rc; \ 	in_pos = rc_in_pos; \ } while (0)
end_define

begin_comment
comment|/// Resets the range decoder structure.
end_comment

begin_define
define|#
directive|define
name|rc_reset
parameter_list|(
name|range_decoder
parameter_list|)
define|\
value|do { \ 	(range_decoder).range = UINT32_MAX; \ 	(range_decoder).code = 0; \ 	(range_decoder).init_bytes_left = 5; \ } while (0)
end_define

begin_comment
comment|/// When decoding has been properly finished, rc.code is always zero unless
end_comment

begin_comment
comment|/// the input stream is corrupt. So checking this can catch some corrupt
end_comment

begin_comment
comment|/// files especially if they don't have any other integrity check.
end_comment

begin_define
define|#
directive|define
name|rc_is_finished
parameter_list|(
name|range_decoder
parameter_list|)
define|\
value|((range_decoder).code == 0)
end_define

begin_comment
comment|/// Read the next input byte if needed. If more input is needed but there is
end_comment

begin_comment
comment|/// no more input available, "goto out" is used to jump out of the main
end_comment

begin_comment
comment|/// decoder loop.
end_comment

begin_define
define|#
directive|define
name|rc_normalize
parameter_list|(
name|seq
parameter_list|)
define|\
value|do { \ 	if (rc.range< RC_TOP_VALUE) { \ 		if (unlikely(rc_in_pos == in_size)) { \ 			coder->sequence = seq; \ 			goto out; \ 		} \ 		rc.range<<= RC_SHIFT_BITS; \ 		rc.code = (rc.code<< RC_SHIFT_BITS) | in[rc_in_pos++]; \ 	} \ } while (0)
end_define

begin_comment
comment|/// Start decoding a bit. This must be used together with rc_update_0()
end_comment

begin_comment
comment|/// and rc_update_1():
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|///     rc_if_0(prob, seq) {
end_comment

begin_comment
comment|///         rc_update_0(prob);
end_comment

begin_comment
comment|///         // Do something
end_comment

begin_comment
comment|///     } else {
end_comment

begin_comment
comment|///         rc_update_1(prob);
end_comment

begin_comment
comment|///         // Do something else
end_comment

begin_comment
comment|///     }
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|rc_if_0
parameter_list|(
name|prob
parameter_list|,
name|seq
parameter_list|)
define|\
value|rc_normalize(seq); \ 	rc_bound = (rc.range>> RC_BIT_MODEL_TOTAL_BITS) * (prob); \ 	if (rc.code< rc_bound)
end_define

begin_comment
comment|/// Update the range decoder state and the used probability variable to
end_comment

begin_comment
comment|/// match a decoded bit of 0.
end_comment

begin_define
define|#
directive|define
name|rc_update_0
parameter_list|(
name|prob
parameter_list|)
define|\
value|do { \ 	rc.range = rc_bound; \ 	prob += (RC_BIT_MODEL_TOTAL - (prob))>> RC_MOVE_BITS; \ } while (0)
end_define

begin_comment
comment|/// Update the range decoder state and the used probability variable to
end_comment

begin_comment
comment|/// match a decoded bit of 1.
end_comment

begin_define
define|#
directive|define
name|rc_update_1
parameter_list|(
name|prob
parameter_list|)
define|\
value|do { \ 	rc.range -= rc_bound; \ 	rc.code -= rc_bound; \ 	prob -= (prob)>> RC_MOVE_BITS; \ } while (0)
end_define

begin_comment
comment|/// Decodes one bit and runs action0 or action1 depending on the decoded bit.
end_comment

begin_comment
comment|/// This macro is used as the last step in bittree reverse decoders since
end_comment

begin_comment
comment|/// those don't use "symbol" for anything else than indexing the probability
end_comment

begin_comment
comment|/// arrays.
end_comment

begin_define
define|#
directive|define
name|rc_bit_last
parameter_list|(
name|prob
parameter_list|,
name|action0
parameter_list|,
name|action1
parameter_list|,
name|seq
parameter_list|)
define|\
value|do { \ 	rc_if_0(prob, seq) { \ 		rc_update_0(prob); \ 		action0; \ 	} else { \ 		rc_update_1(prob); \ 		action1; \ 	} \ } while (0)
end_define

begin_comment
comment|/// Decodes one bit, updates "symbol", and runs action0 or action1 depending
end_comment

begin_comment
comment|/// on the decoded bit.
end_comment

begin_define
define|#
directive|define
name|rc_bit
parameter_list|(
name|prob
parameter_list|,
name|action0
parameter_list|,
name|action1
parameter_list|,
name|seq
parameter_list|)
define|\
value|rc_bit_last(prob, \ 		symbol<<= 1; action0, \ 		symbol = (symbol<< 1) + 1; action1, \ 		seq);
end_define

begin_comment
comment|/// Like rc_bit() but add "case seq:" as a prefix. This makes the unrolled
end_comment

begin_comment
comment|/// loops more readable because the code isn't littered with "case"
end_comment

begin_comment
comment|/// statements. On the other hand this also makes it less readable, since
end_comment

begin_comment
comment|/// spotting the places where the decoder loop may be restarted is less
end_comment

begin_comment
comment|/// obvious.
end_comment

begin_define
define|#
directive|define
name|rc_bit_case
parameter_list|(
name|prob
parameter_list|,
name|action0
parameter_list|,
name|action1
parameter_list|,
name|seq
parameter_list|)
define|\
value|case seq: rc_bit(prob, action0, action1, seq)
end_define

begin_comment
comment|/// Decode a bit without using a probability.
end_comment

begin_define
define|#
directive|define
name|rc_direct
parameter_list|(
name|dest
parameter_list|,
name|seq
parameter_list|)
define|\
value|do { \ 	rc_normalize(seq); \ 	rc.range>>= 1; \ 	rc.code -= rc.range; \ 	rc_bound = UINT32_C(0) - (rc.code>> 31); \ 	rc.code += rc.range& rc_bound; \ 	dest = (dest<< 1) + (rc_bound + 1); \ } while (0)
end_define

begin_comment
comment|// NOTE: No macros are provided for bittree decoding. It seems to be simpler
end_comment

begin_comment
comment|// to just write them open in the code.
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

