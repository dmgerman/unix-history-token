begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* More subroutines needed by GCC output code on some machines.  */
end_comment

begin_comment
comment|/* Compile this one with gcc.  */
end_comment

begin_include
include|#
directive|include
file|"config.h"
end_include

begin_include
include|#
directive|include
file|<stddef.h>
end_include

begin_ifndef
ifndef|#
directive|ifndef
name|SItype
end_ifndef

begin_define
define|#
directive|define
name|SItype
value|long int
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* long long ints are pairs of long ints in the order determined by    WORDS_BIG_ENDIAN.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|WORDS_BIG_ENDIAN
end_ifdef

begin_struct
struct|struct
name|longlong
block|{
name|long
name|high
decl_stmt|,
name|low
decl_stmt|;
block|}
struct|;
end_struct

begin_else
else|#
directive|else
end_else

begin_struct
struct|struct
name|longlong
block|{
name|long
name|low
decl_stmt|,
name|high
decl_stmt|;
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* We need this union to unpack/pack longlongs, since we don't have    any arithmetic yet.  Incoming long long parameters are stored    into the `ll' field, and the unpacked result is read from the struct    longlong.  */
end_comment

begin_typedef
typedef|typedef
union|union
block|{
name|struct
name|longlong
name|s
decl_stmt|;
name|long
name|long
name|ll
decl_stmt|;
name|SItype
name|i
index|[
literal|2
index|]
decl_stmt|;
name|unsigned
name|SItype
name|ui
index|[
literal|2
index|]
decl_stmt|;
block|}
name|long_long
typedef|;
end_typedef

begin_comment
comment|/* Internally, long long ints are strings of unsigned shorts in the    order determined by BYTES_BIG_ENDIAN.  */
end_comment

begin_define
define|#
directive|define
name|B
value|0x10000
end_define

begin_define
define|#
directive|define
name|low16
value|(B - 1)
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|BYTES_BIG_ENDIAN
end_ifdef

begin_comment
comment|/* Note that HIGH and LOW do not describe the order    of words in a long long.  They describe the order of words    in vectors ordered according to the byte order.  */
end_comment

begin_define
define|#
directive|define
name|HIGH
value|0
end_define

begin_define
define|#
directive|define
name|LOW
value|1
end_define

begin_define
define|#
directive|define
name|big_end
parameter_list|(
name|n
parameter_list|)
value|0
end_define

begin_define
define|#
directive|define
name|little_end
parameter_list|(
name|n
parameter_list|)
value|((n) - 1)
end_define

begin_define
define|#
directive|define
name|next_msd
parameter_list|(
name|i
parameter_list|)
value|((i) - 1)
end_define

begin_define
define|#
directive|define
name|next_lsd
parameter_list|(
name|i
parameter_list|)
value|((i) + 1)
end_define

begin_define
define|#
directive|define
name|is_not_msd
parameter_list|(
name|i
parameter_list|,
name|n
parameter_list|)
value|((i)>= 0)
end_define

begin_define
define|#
directive|define
name|is_not_lsd
parameter_list|(
name|i
parameter_list|,
name|n
parameter_list|)
value|((i)< (n))
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|LOW
value|0
end_define

begin_define
define|#
directive|define
name|HIGH
value|1
end_define

begin_define
define|#
directive|define
name|big_end
parameter_list|(
name|n
parameter_list|)
value|((n) - 1)
end_define

begin_define
define|#
directive|define
name|little_end
parameter_list|(
name|n
parameter_list|)
value|0
end_define

begin_define
define|#
directive|define
name|next_msd
parameter_list|(
name|i
parameter_list|)
value|((i) + 1)
end_define

begin_define
define|#
directive|define
name|next_lsd
parameter_list|(
name|i
parameter_list|)
value|((i) - 1)
end_define

begin_define
define|#
directive|define
name|is_not_msd
parameter_list|(
name|i
parameter_list|,
name|n
parameter_list|)
value|((i)< (n))
end_define

begin_define
define|#
directive|define
name|is_not_lsd
parameter_list|(
name|i
parameter_list|,
name|n
parameter_list|)
value|((i)>= 0)
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

