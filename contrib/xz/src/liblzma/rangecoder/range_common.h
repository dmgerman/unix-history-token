begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|///////////////////////////////////////////////////////////////////////////////
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|/// \file       range_common.h
end_comment

begin_comment
comment|/// \brief      Common things for range encoder and decoder
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
name|LZMA_RANGE_COMMON_H
end_ifndef

begin_define
define|#
directive|define
name|LZMA_RANGE_COMMON_H
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_CONFIG_H
end_ifdef

begin_include
include|#
directive|include
file|"common.h"
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|///////////////
end_comment

begin_comment
comment|// Constants //
end_comment

begin_comment
comment|///////////////
end_comment

begin_define
define|#
directive|define
name|RC_SHIFT_BITS
value|8
end_define

begin_define
define|#
directive|define
name|RC_TOP_BITS
value|24
end_define

begin_define
define|#
directive|define
name|RC_TOP_VALUE
value|(UINT32_C(1)<< RC_TOP_BITS)
end_define

begin_define
define|#
directive|define
name|RC_BIT_MODEL_TOTAL_BITS
value|11
end_define

begin_define
define|#
directive|define
name|RC_BIT_MODEL_TOTAL
value|(UINT32_C(1)<< RC_BIT_MODEL_TOTAL_BITS)
end_define

begin_define
define|#
directive|define
name|RC_MOVE_BITS
value|5
end_define

begin_comment
comment|////////////
end_comment

begin_comment
comment|// Macros //
end_comment

begin_comment
comment|////////////
end_comment

begin_comment
comment|// Resets the probability so that both 0 and 1 have probability of 50 %
end_comment

begin_define
define|#
directive|define
name|bit_reset
parameter_list|(
name|prob
parameter_list|)
define|\
value|prob = RC_BIT_MODEL_TOTAL>> 1
end_define

begin_comment
comment|// This does the same for a complete bit tree.
end_comment

begin_comment
comment|// (A tree represented as an array.)
end_comment

begin_define
define|#
directive|define
name|bittree_reset
parameter_list|(
name|probs
parameter_list|,
name|bit_levels
parameter_list|)
define|\
value|for (uint32_t bt_i = 0; bt_i< (1<< (bit_levels)); ++bt_i) \ 		bit_reset((probs)[bt_i])
end_define

begin_comment
comment|//////////////////////
end_comment

begin_comment
comment|// Type definitions //
end_comment

begin_comment
comment|//////////////////////
end_comment

begin_comment
comment|/// \brief      Type of probabilities used with range coder
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This needs to be at least 12-bit integer, so uint16_t is a logical choice.
end_comment

begin_comment
comment|/// However, on some architecture and compiler combinations, a bigger type
end_comment

begin_comment
comment|/// may give better speed, because the probability variables are accessed
end_comment

begin_comment
comment|/// a lot. On the other hand, bigger probability type increases cache
end_comment

begin_comment
comment|/// footprint, since there are 2 to 14 thousand probability variables in
end_comment

begin_comment
comment|/// LZMA (assuming the limit of lc + lp<= 4; with lc + lp<= 12 there
end_comment

begin_comment
comment|/// would be about 1.5 million variables).
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// With malicious files, the initialization speed of the LZMA decoder can
end_comment

begin_comment
comment|/// become important. In that case, smaller probability variables mean that
end_comment

begin_comment
comment|/// there is less bytes to write to RAM, which makes initialization faster.
end_comment

begin_comment
comment|/// With big probability type, the initialization can become so slow that it
end_comment

begin_comment
comment|/// can be a problem e.g. for email servers doing virus scanning.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// I will be sticking to uint16_t unless some specific architectures
end_comment

begin_comment
comment|/// are *much* faster (20-50 %) with uint32_t.
end_comment

begin_typedef
typedef|typedef
name|uint16_t
name|probability
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

end_unit

