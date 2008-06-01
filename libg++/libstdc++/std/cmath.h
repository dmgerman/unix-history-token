begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// The -*- C++ -*- math functions header.
end_comment

begin_comment
comment|// This file is part of the GNU ANSI C++ Library.
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__CMATH__
end_ifndef

begin_define
define|#
directive|define
name|__CMATH__
end_define

begin_include
include|#
directive|include
file|<_G_config.h>
end_include

begin_include
include|#
directive|include
file|<math.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|__GNUG__
end_ifdef

begin_pragma
pragma|#
directive|pragma
name|interface
literal|"std/cmath.h"
end_pragma

begin_endif
endif|#
directive|endif
end_endif

begin_extern
extern|extern
literal|"C++"
block|{
if|#
directive|if
literal|0
block|float acos (float); float asin (float); float atan (float); float atan2(float, float); float ceil (float); float cos  (float); float cosh (float); float exp  (float); float fabs (float); float floor(float); float fmod (float, float); float frexp(float, int*); float modf (float, float*); float ldexp(float, int); float log  (float); float log10(float); float pow  (float, float); float pow  (float, int); float sin  (float); float sinh (float); float sqrt (float); float tan  (float); float tanh (float);
endif|#
directive|endif
specifier|inline
name|float
name|abs
parameter_list|(
name|float
name|x
parameter_list|)
block|{
return|return
name|fabs
argument_list|(
name|x
argument_list|)
return|;
block|}
if|#
directive|if
operator|!
name|_G_MATH_H_INLINES
comment|/* hpux and SCO define this in math.h */
specifier|inline
name|double
name|abs
parameter_list|(
name|double
name|x
parameter_list|)
block|{
return|return
name|fabs
argument_list|(
name|x
argument_list|)
return|;
block|}
endif|#
directive|endif
if|#
directive|if
literal|0
block|double pow(double, int);  long double acos (long double); long double asin (long double); long double atan (long double); long double atan2(long double, long double); long double ceil (long double); long double cos  (long double); long double cosh (long double); long double exp  (long double); long double fabs (long double); long double floor(long double); long double frexp(long double, int*); long double fmod (long double, long double); long double frexp(long double, int*); long double log  (long double); long double log10(long double); long double modf (long double, long double*); long double pow  (long double, long double); long double pow  (long double, int); long double sin  (long double); long double sinh (long double); long double sqrt (long double); long double tan  (long double); long double tanh (long double);
endif|#
directive|endif
specifier|inline
name|long
name|double
name|abs
parameter_list|(
name|long
name|double
name|x
parameter_list|)
block|{
return|return
name|fabs
argument_list|(
name|x
argument_list|)
return|;
block|}
block|}
end_extern

begin_comment
comment|// extern "C++"
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

