begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_ifndef
ifndef|#
directive|ifndef
name|_BS_PRIMS
end_ifndef

begin_define
define|#
directive|define
name|_BS_PRIMS
end_define

begin_comment
comment|/* A bitstring is an array of _BS_word. */
end_comment

begin_typedef
typedef|typedef
name|unsigned
name|long
name|_BS_word
typedef|;
end_typedef

begin_define
define|#
directive|define
name|_BS_CHAR_BIT
value|8
end_define

begin_define
define|#
directive|define
name|_BS_BITS_PER_WORD
value|(_BS_CHAR_BIT*sizeof(_BS_word))
end_define

begin_define
define|#
directive|define
name|_BS_WORDS_NEEDED
parameter_list|(
name|NBITS
parameter_list|)
value|((NBITS+_BS_BITS_PER_WORD-1)/_BS_BITS_PER_WORD)
end_define

begin_comment
comment|/* For now, we number the bits in a _BS_word in little-endian order.    Later, might use machine order. */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|CHILL_LIB
end_ifdef

begin_ifndef
ifndef|#
directive|ifndef
name|BITS_BIG_ENDIAN
end_ifndef

begin_include
include|#
directive|include
file|"config.h"
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|_BS_BIGENDIAN
value|BITS_BIG_ENDIAN
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|_BS_BIGENDIAN
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* By "left" we mean where bit number 0 is.    Hence, so left shift is<< if we're numbering the bits in big-endian oder,    and>> if we're numbering the bits in little-endian order.    Currently, we always use little-endian order.    Later, we might use machine-endian order. */
end_comment

begin_if
if|#
directive|if
name|_BS_BIGENDIAN
end_if

begin_define
define|#
directive|define
name|_BS_LEFT
value|<<
end_define

begin_define
define|#
directive|define
name|_BS_RIGHT
value|>>
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|_BS_LEFT
value|>>
end_define

begin_define
define|#
directive|define
name|_BS_RIGHT
value|<<
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|_BS_BIGENDIAN
end_if

begin_define
define|#
directive|define
name|_BS_BITMASK
parameter_list|(
name|BITNO
parameter_list|)
value|((_BS_word)1<< (_BS_BITS_PER_WORD - 1 - (BITNO)))
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|_BS_BITMASK
parameter_list|(
name|BITNO
parameter_list|)
value|((_BS_word)1<< (BITNO))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Given a PTR which may not be aligned on a _BS_word boundary,    set NEW_PTR to point to (the beginning of) the corresponding _BS_word.    Adjust the bit-offset OFFSET to compensate for the difference. */
end_comment

begin_define
define|#
directive|define
name|_BS_ADJUST_ALIGNED
parameter_list|(
name|NEW_PTR
parameter_list|,
name|PTR
parameter_list|,
name|OFFSET
parameter_list|)
define|\
value|( (NEW_PTR) = (_BS_word*)(((char*)(PTR)-(char*)0)& ~(sizeof(_BS_word)-1)), \     (OFFSET) += (char*)(PTR) - (char*)(NEW_PTR) )
end_define

begin_comment
comment|/* Given a bit pointer (PTR, OFFSET) normalize it so that    OFFSET< _BS_BITS_PER_WORD. */
end_comment

begin_define
define|#
directive|define
name|_BS_NORMALIZE
parameter_list|(
name|PTR
parameter_list|,
name|OFFSET
parameter_list|)
define|\
value|{ _BS_size_t __tmp_ind = _BS_INDEX (OFFSET); \   (PTR) += __tmp_ind; \   (OFFSET) -= __tmp_ind * _BS_BITS_PER_WORD; }
end_define

begin_define
define|#
directive|define
name|_BS_INDEX
parameter_list|(
name|I
parameter_list|)
value|((unsigned)(I) / _BS_BITS_PER_WORD)
end_define

begin_define
define|#
directive|define
name|_BS_POS
parameter_list|(
name|I
parameter_list|)
value|((I)& (_BS_BITS_PER_WORD -1 ))
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|_BS_size_t
end_ifndef

begin_if
if|#
directive|if
name|__GNUC__
operator|>
literal|1
end_if

begin_define
define|#
directive|define
name|_BS_size_t
value|__SIZE_TYPE__
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|_BS_size_t
value|unsigned long
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|__P
end_ifndef

begin_ifdef
ifdef|#
directive|ifdef
name|__STDC__
end_ifdef

begin_define
define|#
directive|define
name|__P
parameter_list|(
name|protos
parameter_list|)
value|protos
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|__P
parameter_list|(
name|protos
parameter_list|)
value|()
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*!__P*/
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|__STDC__
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
specifier|const
argument_list|)
end_if

begin_define
define|#
directive|define
name|const
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|__STDC__
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|void
argument_list|)
end_if

begin_define
define|#
directive|define
name|void
value|int
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* The 16 2-operand raster-ops:    These match the correspodning GX codes in X11. */
end_comment

begin_enum
enum|enum
name|_BS_alu
block|{
name|_BS_alu_clear
init|=
literal|0
comment|/* 0 */
block|,
name|_BS_alu_and
init|=
literal|1
comment|/* src& dst */
block|,
name|_BS_alu_andReverse
init|=
literal|2
comment|/* src& ~dst */
block|,
name|_BS_alu_copy
init|=
literal|3
comment|/* src */
block|,
name|_BS_alu_andInverted
init|=
literal|4
comment|/* ~src& dst */
block|,
name|_BS_alu_noop
init|=
literal|5
comment|/* dst */
block|,
name|_BS_alu_xor
init|=
literal|6
comment|/* src ^ dst */
block|,
name|_BS_alu_or
init|=
literal|7
comment|/* src | dst */
block|,
name|_BS_alu_nor
init|=
literal|8
comment|/* ~src& ~dst */
block|,
name|_BS_alu_equiv
init|=
literal|9
comment|/* ~(src ^ dst) */
block|,
name|_BS_alu_invert
init|=
literal|10
comment|/* ~dst */
block|,
name|_BS_alu_orReverse
init|=
literal|11
comment|/* src | ~dst */
block|,
name|_BS_alu_copyInverted
init|=
literal|12
comment|/* ~src */
block|,
name|_BS_alu_orInverted
init|=
literal|13
comment|/* ~src | dst */
block|,
name|_BS_alu_nand
init|=
literal|14
comment|/* ~src | d~st */
block|,
name|_BS_alu_set
init|=
literal|15
comment|/* ~src | dst */
block|}
enum|;
end_enum

begin_define
define|#
directive|define
name|_BS
end_define

begin_define
define|#
directive|define
name|_BS
end_define

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
specifier|extern
name|void
name|_BS_and
name|__P
argument_list|(
operator|(
name|_BS_word
operator|*
operator|,
name|int
operator|,
specifier|const
name|_BS_word
operator|*
operator|,
name|int
operator|,
name|_BS_size_t
operator|)
argument_list|)
decl_stmt|;
specifier|extern
name|void
name|_BS_blt
name|__P
argument_list|(
operator|(
expr|enum
name|_BS_alu
operator|,
name|_BS_word
operator|*
operator|,
name|int
operator|,
specifier|const
name|_BS_word
operator|*
operator|,
name|int
operator|,
name|_BS_size_t
operator|)
argument_list|)
decl_stmt|;
specifier|extern
name|void
name|_BS_copy
name|__P
argument_list|(
operator|(
name|_BS_word
operator|*
operator|,
name|int
operator|,
specifier|const
name|_BS_word
operator|*
operator|,
name|int
operator|,
name|_BS_size_t
operator|)
argument_list|)
decl_stmt|;
define|#
directive|define
name|_BS_copy_0
parameter_list|(
name|DS
parameter_list|,
name|SS
parameter_list|,
name|LENGTH
parameter_list|)
value|_BS_copy(DS, 0, SS, 0, LENGTH)
specifier|extern
name|int
name|_BS_count
name|__P
argument_list|(
operator|(
specifier|const
name|_BS_word
operator|*
operator|,
name|int
operator|,
name|_BS_size_t
operator|)
argument_list|)
decl_stmt|;
specifier|extern
name|int
name|_BS_any
name|__P
argument_list|(
operator|(
specifier|const
name|_BS_word
operator|*
operator|,
name|int
operator|,
name|_BS_size_t
operator|)
argument_list|)
decl_stmt|;
specifier|extern
name|void
name|_BS_clear
name|__P
argument_list|(
operator|(
name|_BS_word
operator|*
operator|,
name|int
operator|,
name|_BS_size_t
operator|)
argument_list|)
decl_stmt|;
specifier|extern
name|void
name|_BS_set
name|__P
argument_list|(
operator|(
name|_BS_word
operator|*
operator|,
name|int
operator|,
name|_BS_size_t
operator|)
argument_list|)
decl_stmt|;
specifier|extern
name|void
name|_BS_invert
name|__P
argument_list|(
operator|(
name|_BS_word
operator|*
operator|,
name|int
operator|,
name|_BS_size_t
operator|)
argument_list|)
decl_stmt|;
name|int
name|_BS_lcompare_0
name|__P
argument_list|(
operator|(
specifier|const
name|_BS_word
operator|*
operator|,
name|_BS_size_t
operator|,
specifier|const
name|_BS_word
operator|*
operator|,
name|_BS_size_t
operator|)
argument_list|)
decl_stmt|;
specifier|extern
name|void
name|_BS_xor
name|__P
argument_list|(
operator|(
name|_BS_word
operator|*
operator|,
name|int
operator|,
specifier|const
name|_BS_word
operator|*
operator|,
name|int
operator|,
name|_BS_size_t
operator|)
argument_list|)
decl_stmt|;
ifdef|#
directive|ifdef
name|__cplusplus
block|}
end_extern

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_BS_PRIMS */
end_comment

end_unit

