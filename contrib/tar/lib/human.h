begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_ifndef
ifndef|#
directive|ifndef
name|HUMAN_H_
end_ifndef

begin_define
define|#
directive|define
name|HUMAN_H_
value|1
end_define

begin_if
if|#
directive|if
name|HAVE_CONFIG_H
end_if

begin_include
include|#
directive|include
file|<config.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|HAVE_INTTYPES_H
end_if

begin_include
include|#
directive|include
file|<inttypes.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* A conservative bound on the maximum length of a human-readable string.    The output can be the product of the largest uintmax_t and the largest int,    so add their sizes before converting to a bound on digits.  */
end_comment

begin_define
define|#
directive|define
name|LONGEST_HUMAN_READABLE
value|((sizeof (uintmax_t) + sizeof (int)) \ 				 * CHAR_BIT / 3)
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|PARAMS
end_ifndef

begin_if
if|#
directive|if
name|defined
name|PROTOTYPES
operator|||
operator|(
name|defined
name|__STDC__
operator|&&
name|__STDC__
operator|)
end_if

begin_define
define|#
directive|define
name|PARAMS
parameter_list|(
name|Args
parameter_list|)
value|Args
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|PARAMS
parameter_list|(
name|Args
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

begin_enum
enum|enum
name|human_inexact_style
block|{
name|human_floor
init|=
operator|-
literal|1
block|,
name|human_round_to_even
init|=
literal|0
block|,
name|human_ceiling
init|=
literal|1
block|}
enum|;
end_enum

begin_decl_stmt
name|char
modifier|*
name|human_readable
name|PARAMS
argument_list|(
operator|(
name|uintmax_t
operator|,
name|char
operator|*
operator|,
name|int
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|human_readable_inexact
name|PARAMS
argument_list|(
operator|(
name|uintmax_t
operator|,
name|char
operator|*
operator|,
name|int
operator|,
name|int
operator|,
expr|enum
name|human_inexact_style
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|human_block_size
name|PARAMS
argument_list|(
operator|(
name|char
specifier|const
operator|*
operator|,
name|int
operator|,
name|int
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HUMAN_H_ */
end_comment

end_unit

