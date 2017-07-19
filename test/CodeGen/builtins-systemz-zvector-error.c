begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// REQUIRES: systemz-registered-target
end_comment

begin_comment
comment|// RUN: %clang_cc1 -target-cpu z13 -triple s390x-linux-gnu \
end_comment

begin_comment
comment|// RUN: -fzvector -fno-lax-vector-conversions \
end_comment

begin_comment
comment|// RUN: -Wall -Wno-unused -Werror -fsyntax-only -verify %s
end_comment

begin_include
include|#
directive|include
file|<vecintrin.h>
end_include

begin_decl_stmt
specifier|volatile
name|vector
name|signed
name|char
name|vsc
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|volatile
name|vector
name|signed
name|short
name|vss
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|volatile
name|vector
name|signed
name|int
name|vsi
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|volatile
name|vector
name|signed
name|long
name|long
name|vsl
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|volatile
name|vector
name|unsigned
name|char
name|vuc
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|volatile
name|vector
name|unsigned
name|short
name|vus
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|volatile
name|vector
name|unsigned
name|int
name|vui
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|volatile
name|vector
name|unsigned
name|long
name|long
name|vul
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|volatile
name|vector
name|bool
name|char
name|vbc
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|volatile
name|vector
name|bool
name|short
name|vbs
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|volatile
name|vector
name|bool
name|int
name|vbi
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|volatile
name|vector
name|bool
name|long
name|long
name|vbl
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|volatile
name|vector
name|double
name|vd
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|volatile
name|signed
name|char
name|sc
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|volatile
name|signed
name|short
name|ss
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|volatile
name|signed
name|int
name|si
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|volatile
name|signed
name|long
name|long
name|sl
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|volatile
name|unsigned
name|char
name|uc
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|volatile
name|unsigned
name|short
name|us
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|volatile
name|unsigned
name|int
name|ui
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|volatile
name|unsigned
name|long
name|long
name|ul
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|volatile
name|double
name|d
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
name|void
modifier|*
specifier|volatile
name|cptr
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
name|signed
name|char
modifier|*
specifier|volatile
name|cptrsc
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
name|signed
name|short
modifier|*
specifier|volatile
name|cptrss
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
name|signed
name|int
modifier|*
specifier|volatile
name|cptrsi
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
name|signed
name|long
name|long
modifier|*
specifier|volatile
name|cptrsl
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
name|unsigned
name|char
modifier|*
specifier|volatile
name|cptruc
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
name|unsigned
name|short
modifier|*
specifier|volatile
name|cptrus
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
name|unsigned
name|int
modifier|*
specifier|volatile
name|cptrui
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
name|unsigned
name|long
name|long
modifier|*
specifier|volatile
name|cptrul
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
name|float
modifier|*
specifier|volatile
name|cptrf
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
name|double
modifier|*
specifier|volatile
name|cptrd
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
modifier|*
specifier|volatile
name|ptr
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|signed
name|char
modifier|*
specifier|volatile
name|ptrsc
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|signed
name|short
modifier|*
specifier|volatile
name|ptrss
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|signed
name|int
modifier|*
specifier|volatile
name|ptrsi
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|signed
name|long
name|long
modifier|*
specifier|volatile
name|ptrsl
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|unsigned
name|char
modifier|*
specifier|volatile
name|ptruc
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|unsigned
name|short
modifier|*
specifier|volatile
name|ptrus
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|unsigned
name|int
modifier|*
specifier|volatile
name|ptrui
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|unsigned
name|long
name|long
modifier|*
specifier|volatile
name|ptrul
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|float
modifier|*
specifier|volatile
name|ptrf
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|double
modifier|*
specifier|volatile
name|ptrd
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|volatile
name|unsigned
name|int
name|len
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|volatile
name|int
name|idx
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|cc
decl_stmt|;
end_decl_stmt

begin_function
name|void
name|test_core
parameter_list|(
name|void
parameter_list|)
block|{
name|len
operator|=
name|__lcbb
argument_list|(
name|cptr
argument_list|,
name|idx
argument_list|)
expr_stmt|;
comment|// expected-error {{no matching function}}
comment|// expected-note@vecintrin.h:* {{must be a constant power of 2 from 64 to 4096}}
name|len
operator|=
name|__lcbb
argument_list|(
name|cptr
argument_list|,
literal|200
argument_list|)
expr_stmt|;
comment|// expected-error {{no matching function}}
comment|// expected-note@vecintrin.h:* {{must be a constant power of 2 from 64 to 4096}}
name|len
operator|=
name|__lcbb
argument_list|(
name|cptr
argument_list|,
literal|32
argument_list|)
expr_stmt|;
comment|// expected-error {{no matching function}}
comment|// expected-note@vecintrin.h:* {{must be a constant power of 2 from 64 to 4096}}
name|len
operator|=
name|__lcbb
argument_list|(
name|cptr
argument_list|,
literal|8192
argument_list|)
expr_stmt|;
comment|// expected-error {{no matching function}}
comment|// expected-note@vecintrin.h:* {{must be a constant power of 2 from 64 to 4096}}
name|vsl
operator|=
name|vec_permi
argument_list|(
name|vsl
argument_list|,
name|vsl
argument_list|,
name|idx
argument_list|)
expr_stmt|;
comment|// expected-error {{no matching function}}
comment|// expected-note@vecintrin.h:* 3 {{candidate function not viable}}
comment|// expected-note@vecintrin.h:* 1 {{must be a constant integer from 0 to 3}}
name|vsl
operator|=
name|vec_permi
argument_list|(
name|vsl
argument_list|,
name|vsl
argument_list|,
operator|-
literal|1
argument_list|)
expr_stmt|;
comment|// expected-error {{no matching function}}
comment|// expected-note@vecintrin.h:* 3 {{candidate function not viable}}
comment|// expected-note@vecintrin.h:* 1 {{must be a constant integer from 0 to 3}}
name|vsl
operator|=
name|vec_permi
argument_list|(
name|vsl
argument_list|,
name|vsl
argument_list|,
literal|4
argument_list|)
expr_stmt|;
comment|// expected-error {{no matching function}}
comment|// expected-note@vecintrin.h:* 3 {{candidate function not viable}}
comment|// expected-note@vecintrin.h:* 1 {{must be a constant integer from 0 to 3}}
name|vul
operator|=
name|vec_permi
argument_list|(
name|vul
argument_list|,
name|vul
argument_list|,
name|idx
argument_list|)
expr_stmt|;
comment|// expected-error {{no matching function}}
comment|// expected-note@vecintrin.h:* 2 {{candidate function not viable}}
comment|// expected-note@vecintrin.h:* 2 {{must be a constant integer from 0 to 3}}
name|vul
operator|=
name|vec_permi
argument_list|(
name|vul
argument_list|,
name|vul
argument_list|,
operator|-
literal|1
argument_list|)
expr_stmt|;
comment|// expected-error {{no matching function}}
comment|// expected-note@vecintrin.h:* 2 {{candidate function not viable}}
comment|// expected-note@vecintrin.h:* 2 {{must be a constant integer from 0 to 3}}
name|vul
operator|=
name|vec_permi
argument_list|(
name|vul
argument_list|,
name|vul
argument_list|,
literal|4
argument_list|)
expr_stmt|;
comment|// expected-error {{no matching function}}
comment|// expected-note@vecintrin.h:* 2 {{candidate function not viable}}
comment|// expected-note@vecintrin.h:* 2 {{must be a constant integer from 0 to 3}}
name|vbl
operator|=
name|vec_permi
argument_list|(
name|vbl
argument_list|,
name|vbl
argument_list|,
name|idx
argument_list|)
expr_stmt|;
comment|// expected-error {{no matching function}}
comment|// expected-note@vecintrin.h:* 2 {{candidate function not viable}}
comment|// expected-note@vecintrin.h:* 2 {{must be a constant integer from 0 to 3}}
name|vbl
operator|=
name|vec_permi
argument_list|(
name|vbl
argument_list|,
name|vbl
argument_list|,
operator|-
literal|1
argument_list|)
expr_stmt|;
comment|// expected-error {{no matching function}}
comment|// expected-note@vecintrin.h:* 2 {{candidate function not viable}}
comment|// expected-note@vecintrin.h:* 2 {{must be a constant integer from 0 to 3}}
name|vbl
operator|=
name|vec_permi
argument_list|(
name|vbl
argument_list|,
name|vbl
argument_list|,
literal|4
argument_list|)
expr_stmt|;
comment|// expected-error {{no matching function}}
comment|// expected-note@vecintrin.h:* 2 {{candidate function not viable}}
comment|// expected-note@vecintrin.h:* 2 {{must be a constant integer from 0 to 3}}
name|vd
operator|=
name|vec_permi
argument_list|(
name|vd
argument_list|,
name|vd
argument_list|,
name|idx
argument_list|)
expr_stmt|;
comment|// expected-error {{no matching function}}
comment|// expected-note@vecintrin.h:* 3 {{candidate function not viable}}
comment|// expected-note@vecintrin.h:* 1 {{must be a constant integer from 0 to 3}}
name|vd
operator|=
name|vec_permi
argument_list|(
name|vd
argument_list|,
name|vd
argument_list|,
operator|-
literal|1
argument_list|)
expr_stmt|;
comment|// expected-error {{no matching function}}
comment|// expected-note@vecintrin.h:* 3 {{candidate function not viable}}
comment|// expected-note@vecintrin.h:* 1 {{must be a constant integer from 0 to 3}}
name|vd
operator|=
name|vec_permi
argument_list|(
name|vd
argument_list|,
name|vd
argument_list|,
literal|4
argument_list|)
expr_stmt|;
comment|// expected-error {{no matching function}}
comment|// expected-note@vecintrin.h:* 3 {{candidate function not viable}}
comment|// expected-note@vecintrin.h:* 1 {{must be a constant integer from 0 to 3}}
name|vsi
operator|=
name|vec_gather_element
argument_list|(
name|vsi
argument_list|,
name|vui
argument_list|,
name|cptrsi
argument_list|,
name|idx
argument_list|)
expr_stmt|;
comment|// expected-error {{no matching function}}
comment|// expected-note@vecintrin.h:* 6 {{candidate function not viable}}
comment|// expected-note@vecintrin.h:* 1 {{must be a constant integer from 0 to 3}}
name|vsi
operator|=
name|vec_gather_element
argument_list|(
name|vsi
argument_list|,
name|vui
argument_list|,
name|cptrsi
argument_list|,
operator|-
literal|1
argument_list|)
expr_stmt|;
comment|// expected-error {{no matching function}}
comment|// expected-note@vecintrin.h:* 6 {{candidate function not viable}}
comment|// expected-note@vecintrin.h:* 1 {{must be a constant integer from 0 to 3}}
name|vsi
operator|=
name|vec_gather_element
argument_list|(
name|vsi
argument_list|,
name|vui
argument_list|,
name|cptrsi
argument_list|,
literal|4
argument_list|)
expr_stmt|;
comment|// expected-error {{no matching function}}
comment|// expected-note@vecintrin.h:* 6 {{candidate function not viable}}
comment|// expected-note@vecintrin.h:* 1 {{must be a constant integer from 0 to 3}}
name|vui
operator|=
name|vec_gather_element
argument_list|(
name|vui
argument_list|,
name|vui
argument_list|,
name|cptrui
argument_list|,
name|idx
argument_list|)
expr_stmt|;
comment|// expected-error {{no matching function}}
comment|// expected-note@vecintrin.h:* 5 {{candidate function not viable}}
comment|// expected-note@vecintrin.h:* 2 {{must be a constant integer from 0 to 3}}
name|vui
operator|=
name|vec_gather_element
argument_list|(
name|vui
argument_list|,
name|vui
argument_list|,
name|cptrui
argument_list|,
operator|-
literal|1
argument_list|)
expr_stmt|;
comment|// expected-error {{no matching function}}
comment|// expected-note@vecintrin.h:* 5 {{candidate function not viable}}
comment|// expected-note@vecintrin.h:* 2 {{must be a constant integer from 0 to 3}}
name|vui
operator|=
name|vec_gather_element
argument_list|(
name|vui
argument_list|,
name|vui
argument_list|,
name|cptrui
argument_list|,
literal|4
argument_list|)
expr_stmt|;
comment|// expected-error {{no matching function}}
comment|// expected-note@vecintrin.h:* 5 {{candidate function not viable}}
comment|// expected-note@vecintrin.h:* 2 {{must be a constant integer from 0 to 3}}
name|vbi
operator|=
name|vec_gather_element
argument_list|(
name|vbi
argument_list|,
name|vui
argument_list|,
name|cptrui
argument_list|,
name|idx
argument_list|)
expr_stmt|;
comment|// expected-error {{no matching function}}
comment|// expected-note@vecintrin.h:* 5 {{candidate function not viable}}
comment|// expected-note@vecintrin.h:* 2 {{must be a constant integer from 0 to 3}}
name|vbi
operator|=
name|vec_gather_element
argument_list|(
name|vbi
argument_list|,
name|vui
argument_list|,
name|cptrui
argument_list|,
operator|-
literal|1
argument_list|)
expr_stmt|;
comment|// expected-error {{no matching function}}
comment|// expected-note@vecintrin.h:* 5 {{candidate function not viable}}
comment|// expected-note@vecintrin.h:* 2 {{must be a constant integer from 0 to 3}}
name|vbi
operator|=
name|vec_gather_element
argument_list|(
name|vbi
argument_list|,
name|vui
argument_list|,
name|cptrui
argument_list|,
literal|4
argument_list|)
expr_stmt|;
comment|// expected-error {{no matching function}}
comment|// expected-note@vecintrin.h:* 5 {{candidate function not viable}}
comment|// expected-note@vecintrin.h:* 2 {{must be a constant integer from 0 to 3}}
name|vsl
operator|=
name|vec_gather_element
argument_list|(
name|vsl
argument_list|,
name|vul
argument_list|,
name|cptrsl
argument_list|,
name|idx
argument_list|)
expr_stmt|;
comment|// expected-error {{no matching function}}
comment|// expected-note@vecintrin.h:* 6 {{candidate function not viable}}
comment|// expected-note@vecintrin.h:* 1 {{must be a constant integer from 0 to 1}}
name|vsl
operator|=
name|vec_gather_element
argument_list|(
name|vsl
argument_list|,
name|vul
argument_list|,
name|cptrsl
argument_list|,
operator|-
literal|1
argument_list|)
expr_stmt|;
comment|// expected-error {{no matching function}}
comment|// expected-note@vecintrin.h:* 6 {{candidate function not viable}}
comment|// expected-note@vecintrin.h:* 1 {{must be a constant integer from 0 to 1}}
name|vsl
operator|=
name|vec_gather_element
argument_list|(
name|vsl
argument_list|,
name|vul
argument_list|,
name|cptrsl
argument_list|,
literal|2
argument_list|)
expr_stmt|;
comment|// expected-error {{no matching function}}
comment|// expected-note@vecintrin.h:* 6 {{candidate function not viable}}
comment|// expected-note@vecintrin.h:* 1 {{must be a constant integer from 0 to 1}}
name|vul
operator|=
name|vec_gather_element
argument_list|(
name|vul
argument_list|,
name|vul
argument_list|,
name|cptrul
argument_list|,
name|idx
argument_list|)
expr_stmt|;
comment|// expected-error {{no matching function}}
comment|// expected-note@vecintrin.h:* 5 {{candidate function not viable}}
comment|// expected-note@vecintrin.h:* 2 {{must be a constant integer from 0 to 1}}
name|vul
operator|=
name|vec_gather_element
argument_list|(
name|vul
argument_list|,
name|vul
argument_list|,
name|cptrul
argument_list|,
operator|-
literal|1
argument_list|)
expr_stmt|;
comment|// expected-error {{no matching function}}
comment|// expected-note@vecintrin.h:* 5 {{candidate function not viable}}
comment|// expected-note@vecintrin.h:* 2 {{must be a constant integer from 0 to 1}}
name|vul
operator|=
name|vec_gather_element
argument_list|(
name|vul
argument_list|,
name|vul
argument_list|,
name|cptrul
argument_list|,
literal|2
argument_list|)
expr_stmt|;
comment|// expected-error {{no matching function}}
comment|// expected-note@vecintrin.h:* 5 {{candidate function not viable}}
comment|// expected-note@vecintrin.h:* 2 {{must be a constant integer from 0 to 1}}
name|vbl
operator|=
name|vec_gather_element
argument_list|(
name|vbl
argument_list|,
name|vul
argument_list|,
name|cptrul
argument_list|,
name|idx
argument_list|)
expr_stmt|;
comment|// expected-error {{no matching function}}
comment|// expected-note@vecintrin.h:* 5 {{candidate function not viable}}
comment|// expected-note@vecintrin.h:* 2 {{must be a constant integer from 0 to 1}}
name|vbl
operator|=
name|vec_gather_element
argument_list|(
name|vbl
argument_list|,
name|vul
argument_list|,
name|cptrul
argument_list|,
operator|-
literal|1
argument_list|)
expr_stmt|;
comment|// expected-error {{no matching function}}
comment|// expected-note@vecintrin.h:* 5 {{candidate function not viable}}
comment|// expected-note@vecintrin.h:* 2 {{must be a constant integer from 0 to 1}}
name|vbl
operator|=
name|vec_gather_element
argument_list|(
name|vbl
argument_list|,
name|vul
argument_list|,
name|cptrul
argument_list|,
literal|2
argument_list|)
expr_stmt|;
comment|// expected-error {{no matching function}}
comment|// expected-note@vecintrin.h:* 5 {{candidate function not viable}}
comment|// expected-note@vecintrin.h:* 2 {{must be a constant integer from 0 to 1}}
name|vd
operator|=
name|vec_gather_element
argument_list|(
name|vd
argument_list|,
name|vul
argument_list|,
name|cptrd
argument_list|,
name|idx
argument_list|)
expr_stmt|;
comment|// expected-error {{no matching function}}
comment|// expected-note@vecintrin.h:* 6 {{candidate function not viable}}
comment|// expected-note@vecintrin.h:* 1 {{must be a constant integer from 0 to 1}}
name|vd
operator|=
name|vec_gather_element
argument_list|(
name|vd
argument_list|,
name|vul
argument_list|,
name|cptrd
argument_list|,
operator|-
literal|1
argument_list|)
expr_stmt|;
comment|// expected-error {{no matching function}}
comment|// expected-note@vecintrin.h:* 6 {{candidate function not viable}}
comment|// expected-note@vecintrin.h:* 1 {{must be a constant integer from 0 to 1}}
name|vd
operator|=
name|vec_gather_element
argument_list|(
name|vd
argument_list|,
name|vul
argument_list|,
name|cptrd
argument_list|,
literal|2
argument_list|)
expr_stmt|;
comment|// expected-error {{no matching function}}
comment|// expected-note@vecintrin.h:* 6 {{candidate function not viable}}
comment|// expected-note@vecintrin.h:* 1 {{must be a constant integer from 0 to 1}}
name|vec_scatter_element
argument_list|(
name|vsi
argument_list|,
name|vui
argument_list|,
name|ptrsi
argument_list|,
name|idx
argument_list|)
expr_stmt|;
comment|// expected-error {{no matching function}}
comment|// expected-note@vecintrin.h:* 6 {{candidate function not viable}}
comment|// expected-note@vecintrin.h:* 1 {{must be a constant integer from 0 to 3}}
name|vec_scatter_element
argument_list|(
name|vsi
argument_list|,
name|vui
argument_list|,
name|ptrsi
argument_list|,
operator|-
literal|1
argument_list|)
expr_stmt|;
comment|// expected-error {{no matching function}}
comment|// expected-note@vecintrin.h:* 6 {{candidate function not viable}}
comment|// expected-note@vecintrin.h:* 1 {{must be a constant integer from 0 to 3}}
name|vec_scatter_element
argument_list|(
name|vsi
argument_list|,
name|vui
argument_list|,
name|ptrsi
argument_list|,
literal|4
argument_list|)
expr_stmt|;
comment|// expected-error {{no matching function}}
comment|// expected-note@vecintrin.h:* 6 {{candidate function not viable}}
comment|// expected-note@vecintrin.h:* 1 {{must be a constant integer from 0 to 3}}
name|vec_scatter_element
argument_list|(
name|vui
argument_list|,
name|vui
argument_list|,
name|ptrui
argument_list|,
name|idx
argument_list|)
expr_stmt|;
comment|// expected-error {{no matching function}}
comment|// expected-note@vecintrin.h:* 5 {{candidate function not viable}}
comment|// expected-note@vecintrin.h:* 2 {{must be a constant integer from 0 to 3}}
name|vec_scatter_element
argument_list|(
name|vui
argument_list|,
name|vui
argument_list|,
name|ptrui
argument_list|,
operator|-
literal|1
argument_list|)
expr_stmt|;
comment|// expected-error {{no matching function}}
comment|// expected-note@vecintrin.h:* 5 {{candidate function not viable}}
comment|// expected-note@vecintrin.h:* 2 {{must be a constant integer from 0 to 3}}
name|vec_scatter_element
argument_list|(
name|vui
argument_list|,
name|vui
argument_list|,
name|ptrui
argument_list|,
literal|4
argument_list|)
expr_stmt|;
comment|// expected-error {{no matching function}}
comment|// expected-note@vecintrin.h:* 5 {{candidate function not viable}}
comment|// expected-note@vecintrin.h:* 2 {{must be a constant integer from 0 to 3}}
name|vec_scatter_element
argument_list|(
name|vbi
argument_list|,
name|vui
argument_list|,
name|ptrui
argument_list|,
name|idx
argument_list|)
expr_stmt|;
comment|// expected-error {{no matching function}}
comment|// expected-note@vecintrin.h:* 5 {{candidate function not viable}}
comment|// expected-note@vecintrin.h:* 2 {{must be a constant integer from 0 to 3}}
name|vec_scatter_element
argument_list|(
name|vbi
argument_list|,
name|vui
argument_list|,
name|ptrui
argument_list|,
operator|-
literal|1
argument_list|)
expr_stmt|;
comment|// expected-error {{no matching function}}
comment|// expected-note@vecintrin.h:* 5 {{candidate function not viable}}
comment|// expected-note@vecintrin.h:* 2 {{must be a constant integer from 0 to 3}}
name|vec_scatter_element
argument_list|(
name|vbi
argument_list|,
name|vui
argument_list|,
name|ptrui
argument_list|,
literal|4
argument_list|)
expr_stmt|;
comment|// expected-error {{no matching function}}
comment|// expected-note@vecintrin.h:* 5 {{candidate function not viable}}
comment|// expected-note@vecintrin.h:* 2 {{must be a constant integer from 0 to 3}}
name|vec_scatter_element
argument_list|(
name|vsl
argument_list|,
name|vul
argument_list|,
name|ptrsl
argument_list|,
name|idx
argument_list|)
expr_stmt|;
comment|// expected-error {{no matching function}}
comment|// expected-note@vecintrin.h:* 6 {{candidate function not viable}}
comment|// expected-note@vecintrin.h:* 1 {{must be a constant integer from 0 to 1}}
name|vec_scatter_element
argument_list|(
name|vsl
argument_list|,
name|vul
argument_list|,
name|ptrsl
argument_list|,
operator|-
literal|1
argument_list|)
expr_stmt|;
comment|// expected-error {{no matching function}}
comment|// expected-note@vecintrin.h:* 6 {{candidate function not viable}}
comment|// expected-note@vecintrin.h:* 1 {{must be a constant integer from 0 to 1}}
name|vec_scatter_element
argument_list|(
name|vsl
argument_list|,
name|vul
argument_list|,
name|ptrsl
argument_list|,
literal|2
argument_list|)
expr_stmt|;
comment|// expected-error {{no matching function}}
comment|// expected-note@vecintrin.h:* 6 {{candidate function not viable}}
comment|// expected-note@vecintrin.h:* 1 {{must be a constant integer from 0 to 1}}
name|vec_scatter_element
argument_list|(
name|vul
argument_list|,
name|vul
argument_list|,
name|ptrul
argument_list|,
name|idx
argument_list|)
expr_stmt|;
comment|// expected-error {{no matching function}}
comment|// expected-note@vecintrin.h:* 5 {{candidate function not viable}}
comment|// expected-note@vecintrin.h:* 2 {{must be a constant integer from 0 to 1}}
name|vec_scatter_element
argument_list|(
name|vul
argument_list|,
name|vul
argument_list|,
name|ptrul
argument_list|,
operator|-
literal|1
argument_list|)
expr_stmt|;
comment|// expected-error {{no matching function}}
comment|// expected-note@vecintrin.h:* 5 {{candidate function not viable}}
comment|// expected-note@vecintrin.h:* 2 {{must be a constant integer from 0 to 1}}
name|vec_scatter_element
argument_list|(
name|vul
argument_list|,
name|vul
argument_list|,
name|ptrul
argument_list|,
literal|2
argument_list|)
expr_stmt|;
comment|// expected-error {{no matching function}}
comment|// expected-note@vecintrin.h:* 5 {{candidate function not viable}}
comment|// expected-note@vecintrin.h:* 2 {{must be a constant integer from 0 to 1}}
name|vec_scatter_element
argument_list|(
name|vbl
argument_list|,
name|vul
argument_list|,
name|ptrul
argument_list|,
name|idx
argument_list|)
expr_stmt|;
comment|// expected-error {{no matching function}}
comment|// expected-note@vecintrin.h:* 5 {{candidate function not viable}}
comment|// expected-note@vecintrin.h:* 2 {{must be a constant integer from 0 to 1}}
name|vec_scatter_element
argument_list|(
name|vbl
argument_list|,
name|vul
argument_list|,
name|ptrul
argument_list|,
operator|-
literal|1
argument_list|)
expr_stmt|;
comment|// expected-error {{no matching function}}
comment|// expected-note@vecintrin.h:* 5 {{candidate function not viable}}
comment|// expected-note@vecintrin.h:* 2 {{must be a constant integer from 0 to 1}}
name|vec_scatter_element
argument_list|(
name|vbl
argument_list|,
name|vul
argument_list|,
name|ptrul
argument_list|,
literal|2
argument_list|)
expr_stmt|;
comment|// expected-error {{no matching function}}
comment|// expected-note@vecintrin.h:* 5 {{candidate function not viable}}
comment|// expected-note@vecintrin.h:* 2 {{must be a constant integer from 0 to 1}}
name|vec_scatter_element
argument_list|(
name|vd
argument_list|,
name|vul
argument_list|,
name|ptrd
argument_list|,
name|idx
argument_list|)
expr_stmt|;
comment|// expected-error {{no matching function}}
comment|// expected-note@vecintrin.h:* 6 {{candidate function not viable}}
comment|// expected-note@vecintrin.h:* 1 {{must be a constant integer from 0 to 1}}
name|vec_scatter_element
argument_list|(
name|vd
argument_list|,
name|vul
argument_list|,
name|ptrd
argument_list|,
operator|-
literal|1
argument_list|)
expr_stmt|;
comment|// expected-error {{no matching function}}
comment|// expected-note@vecintrin.h:* 6 {{candidate function not viable}}
comment|// expected-note@vecintrin.h:* 1 {{must be a constant integer from 0 to 1}}
name|vec_scatter_element
argument_list|(
name|vd
argument_list|,
name|vul
argument_list|,
name|ptrd
argument_list|,
literal|2
argument_list|)
expr_stmt|;
comment|// expected-error {{no matching function}}
comment|// expected-note@vecintrin.h:* 6 {{candidate function not viable}}
comment|// expected-note@vecintrin.h:* 1 {{must be a constant integer from 0 to 1}}
name|vsc
operator|=
name|vec_load_bndry
argument_list|(
name|cptrsc
argument_list|,
name|idx
argument_list|)
expr_stmt|;
comment|// expected-error {{no matching function}}
comment|// expected-note@vecintrin.h:* 9 {{must be a constant power of 2 from 64 to 4096}}
name|vsc
operator|=
name|vec_load_bndry
argument_list|(
name|cptrsc
argument_list|,
literal|200
argument_list|)
expr_stmt|;
comment|// expected-error {{no matching function}}
comment|// expected-note@vecintrin.h:* 9 {{must be a constant power of 2 from 64 to 4096}}
name|vsc
operator|=
name|vec_load_bndry
argument_list|(
name|cptrsc
argument_list|,
literal|32
argument_list|)
expr_stmt|;
comment|// expected-error {{no matching function}}
comment|// expected-note@vecintrin.h:* 9 {{must be a constant power of 2 from 64 to 4096}}
name|vsc
operator|=
name|vec_load_bndry
argument_list|(
name|cptrsc
argument_list|,
literal|8192
argument_list|)
expr_stmt|;
comment|// expected-error {{no matching function}}
comment|// expected-note@vecintrin.h:* 9 {{must be a constant power of 2 from 64 to 4096}}
name|vuc
operator|=
name|vec_load_bndry
argument_list|(
name|cptruc
argument_list|,
name|idx
argument_list|)
expr_stmt|;
comment|// expected-error {{no matching function}}
comment|// expected-note@vecintrin.h:* 9 {{must be a constant power of 2 from 64 to 4096}}
name|vss
operator|=
name|vec_load_bndry
argument_list|(
name|cptrss
argument_list|,
name|idx
argument_list|)
expr_stmt|;
comment|// expected-error {{no matching function}}
comment|// expected-note@vecintrin.h:* 9 {{must be a constant power of 2 from 64 to 4096}}
name|vus
operator|=
name|vec_load_bndry
argument_list|(
name|cptrus
argument_list|,
name|idx
argument_list|)
expr_stmt|;
comment|// expected-error {{no matching function}}
comment|// expected-note@vecintrin.h:* 9 {{must be a constant power of 2 from 64 to 4096}}
name|vsi
operator|=
name|vec_load_bndry
argument_list|(
name|cptrsi
argument_list|,
name|idx
argument_list|)
expr_stmt|;
comment|// expected-error {{no matching function}}
comment|// expected-note@vecintrin.h:* 9 {{must be a constant power of 2 from 64 to 4096}}
name|vui
operator|=
name|vec_load_bndry
argument_list|(
name|cptrui
argument_list|,
name|idx
argument_list|)
expr_stmt|;
comment|// expected-error {{no matching function}}
comment|// expected-note@vecintrin.h:* 9 {{must be a constant power of 2 from 64 to 4096}}
name|vsl
operator|=
name|vec_load_bndry
argument_list|(
name|cptrsl
argument_list|,
name|idx
argument_list|)
expr_stmt|;
comment|// expected-error {{no matching function}}
comment|// expected-note@vecintrin.h:* 9 {{must be a constant power of 2 from 64 to 4096}}
name|vul
operator|=
name|vec_load_bndry
argument_list|(
name|cptrul
argument_list|,
name|idx
argument_list|)
expr_stmt|;
comment|// expected-error {{no matching function}}
comment|// expected-note@vecintrin.h:* 9 {{must be a constant power of 2 from 64 to 4096}}
name|vuc
operator|=
name|vec_genmask
argument_list|(
name|idx
argument_list|)
expr_stmt|;
comment|// expected-error {{no matching function}}
comment|// expected-note@vecintrin.h:* {{must be a constant integer}}
name|vuc
operator|=
name|vec_genmasks_8
argument_list|(
literal|0
argument_list|,
name|idx
argument_list|)
expr_stmt|;
comment|// expected-error {{no matching function}}
comment|// expected-note@vecintrin.h:* {{must be a constant integer}}
name|vuc
operator|=
name|vec_genmasks_8
argument_list|(
name|idx
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// expected-error {{no matching function}}
comment|// expected-note@vecintrin.h:* {{must be a constant integer}}
name|vuc
operator|=
name|vec_genmasks_8
argument_list|(
name|idx
argument_list|,
name|idx
argument_list|)
expr_stmt|;
comment|// expected-error {{no matching function}}
comment|// expected-note@vecintrin.h:* {{must be a constant integer}}
name|vus
operator|=
name|vec_genmasks_16
argument_list|(
literal|0
argument_list|,
name|idx
argument_list|)
expr_stmt|;
comment|// expected-error {{no matching function}}
comment|// expected-note@vecintrin.h:* {{must be a constant integer}}
name|vus
operator|=
name|vec_genmasks_16
argument_list|(
name|idx
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// expected-error {{no matching function}}
comment|// expected-note@vecintrin.h:* {{must be a constant integer}}
name|vus
operator|=
name|vec_genmasks_16
argument_list|(
name|idx
argument_list|,
name|idx
argument_list|)
expr_stmt|;
comment|// expected-error {{no matching function}}
comment|// expected-note@vecintrin.h:* {{must be a constant integer}}
name|vui
operator|=
name|vec_genmasks_32
argument_list|(
literal|0
argument_list|,
name|idx
argument_list|)
expr_stmt|;
comment|// expected-error {{no matching function}}
comment|// expected-note@vecintrin.h:* {{must be a constant integer}}
name|vui
operator|=
name|vec_genmasks_32
argument_list|(
name|idx
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// expected-error {{no matching function}}
comment|// expected-note@vecintrin.h:* {{must be a constant integer}}
name|vui
operator|=
name|vec_genmasks_32
argument_list|(
name|idx
argument_list|,
name|idx
argument_list|)
expr_stmt|;
comment|// expected-error {{no matching function}}
comment|// expected-note@vecintrin.h:* {{must be a constant integer}}
name|vul
operator|=
name|vec_genmasks_64
argument_list|(
literal|0
argument_list|,
name|idx
argument_list|)
expr_stmt|;
comment|// expected-error {{no matching function}}
comment|// expected-note@vecintrin.h:* {{must be a constant integer}}
name|vul
operator|=
name|vec_genmasks_64
argument_list|(
name|idx
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// expected-error {{no matching function}}
comment|// expected-note@vecintrin.h:* {{must be a constant integer}}
name|vul
operator|=
name|vec_genmasks_64
argument_list|(
name|idx
argument_list|,
name|idx
argument_list|)
expr_stmt|;
comment|// expected-error {{no matching function}}
comment|// expected-note@vecintrin.h:* {{must be a constant integer}}
name|vsc
operator|=
name|vec_splat
argument_list|(
name|vsc
argument_list|,
name|idx
argument_list|)
expr_stmt|;
comment|// expected-error {{no matching function}}
comment|// expected-note@vecintrin.h:* 12 {{candidate function not viable}}
comment|// expected-note@vecintrin.h:* 1 {{must be a constant integer from 0 to 15}}
name|vsc
operator|=
name|vec_splat
argument_list|(
name|vsc
argument_list|,
operator|-
literal|1
argument_list|)
expr_stmt|;
comment|// expected-error {{no matching function}}
comment|// expected-note@vecintrin.h:* 12 {{candidate function not viable}}
comment|// expected-note@vecintrin.h:* 1 {{must be a constant integer from 0 to 15}}
name|vsc
operator|=
name|vec_splat
argument_list|(
name|vsc
argument_list|,
literal|16
argument_list|)
expr_stmt|;
comment|// expected-error {{no matching function}}
comment|// expected-note@vecintrin.h:* 12 {{candidate function not viable}}
comment|// expected-note@vecintrin.h:* 1 {{must be a constant integer from 0 to 15}}
name|vuc
operator|=
name|vec_splat
argument_list|(
name|vuc
argument_list|,
name|idx
argument_list|)
expr_stmt|;
comment|// expected-error {{no matching function}}
comment|// expected-note@vecintrin.h:* 11 {{candidate function not viable}}
comment|// expected-note@vecintrin.h:* 2 {{must be a constant integer from 0 to 15}}
name|vuc
operator|=
name|vec_splat
argument_list|(
name|vuc
argument_list|,
operator|-
literal|1
argument_list|)
expr_stmt|;
comment|// expected-error {{no matching function}}
comment|// expected-note@vecintrin.h:* 11 {{candidate function not viable}}
comment|// expected-note@vecintrin.h:* 2 {{must be a constant integer from 0 to 15}}
name|vuc
operator|=
name|vec_splat
argument_list|(
name|vuc
argument_list|,
literal|16
argument_list|)
expr_stmt|;
comment|// expected-error {{no matching function}}
comment|// expected-note@vecintrin.h:* 11 {{candidate function not viable}}
comment|// expected-note@vecintrin.h:* 2 {{must be a constant integer from 0 to 15}}
name|vbc
operator|=
name|vec_splat
argument_list|(
name|vbc
argument_list|,
name|idx
argument_list|)
expr_stmt|;
comment|// expected-error {{no matching function}}
comment|// expected-note@vecintrin.h:* 11 {{candidate function not viable}}
comment|// expected-note@vecintrin.h:* 2 {{must be a constant integer from 0 to 15}}
name|vbc
operator|=
name|vec_splat
argument_list|(
name|vbc
argument_list|,
operator|-
literal|1
argument_list|)
expr_stmt|;
comment|// expected-error {{no matching function}}
comment|// expected-note@vecintrin.h:* 11 {{candidate function not viable}}
comment|// expected-note@vecintrin.h:* 2 {{must be a constant integer from 0 to 15}}
name|vbc
operator|=
name|vec_splat
argument_list|(
name|vbc
argument_list|,
literal|16
argument_list|)
expr_stmt|;
comment|// expected-error {{no matching function}}
comment|// expected-note@vecintrin.h:* 11 {{candidate function not viable}}
comment|// expected-note@vecintrin.h:* 2 {{must be a constant integer from 0 to 15}}
name|vss
operator|=
name|vec_splat
argument_list|(
name|vss
argument_list|,
name|idx
argument_list|)
expr_stmt|;
comment|// expected-error {{no matching function}}
comment|// expected-note@vecintrin.h:* 12 {{candidate function not viable}}
comment|// expected-note@vecintrin.h:* 1 {{must be a constant integer from 0 to 7}}
name|vss
operator|=
name|vec_splat
argument_list|(
name|vss
argument_list|,
operator|-
literal|1
argument_list|)
expr_stmt|;
comment|// expected-error {{no matching function}}
comment|// expected-note@vecintrin.h:* 12 {{candidate function not viable}}
comment|// expected-note@vecintrin.h:* 1 {{must be a constant integer from 0 to 7}}
name|vss
operator|=
name|vec_splat
argument_list|(
name|vss
argument_list|,
literal|8
argument_list|)
expr_stmt|;
comment|// expected-error {{no matching function}}
comment|// expected-note@vecintrin.h:* 12 {{candidate function not viable}}
comment|// expected-note@vecintrin.h:* 1 {{must be a constant integer from 0 to 7}}
name|vus
operator|=
name|vec_splat
argument_list|(
name|vus
argument_list|,
name|idx
argument_list|)
expr_stmt|;
comment|// expected-error {{no matching function}}
comment|// expected-note@vecintrin.h:* 11 {{candidate function not viable}}
comment|// expected-note@vecintrin.h:* 2 {{must be a constant integer from 0 to 7}}
name|vus
operator|=
name|vec_splat
argument_list|(
name|vus
argument_list|,
operator|-
literal|1
argument_list|)
expr_stmt|;
comment|// expected-error {{no matching function}}
comment|// expected-note@vecintrin.h:* 11 {{candidate function not viable}}
comment|// expected-note@vecintrin.h:* 2 {{must be a constant integer from 0 to 7}}
name|vus
operator|=
name|vec_splat
argument_list|(
name|vus
argument_list|,
literal|8
argument_list|)
expr_stmt|;
comment|// expected-error {{no matching function}}
comment|// expected-note@vecintrin.h:* 11 {{candidate function not viable}}
comment|// expected-note@vecintrin.h:* 2 {{must be a constant integer from 0 to 7}}
name|vbs
operator|=
name|vec_splat
argument_list|(
name|vbs
argument_list|,
name|idx
argument_list|)
expr_stmt|;
comment|// expected-error {{no matching function}}
comment|// expected-note@vecintrin.h:* 11 {{candidate function not viable}}
comment|// expected-note@vecintrin.h:* 2 {{must be a constant integer from 0 to 7}}
name|vbs
operator|=
name|vec_splat
argument_list|(
name|vbs
argument_list|,
operator|-
literal|1
argument_list|)
expr_stmt|;
comment|// expected-error {{no matching function}}
comment|// expected-note@vecintrin.h:* 11 {{candidate function not viable}}
comment|// expected-note@vecintrin.h:* 2 {{must be a constant integer from 0 to 7}}
name|vbs
operator|=
name|vec_splat
argument_list|(
name|vbs
argument_list|,
literal|8
argument_list|)
expr_stmt|;
comment|// expected-error {{no matching function}}
comment|// expected-note@vecintrin.h:* 11 {{candidate function not viable}}
comment|// expected-note@vecintrin.h:* 2 {{must be a constant integer from 0 to 7}}
name|vsi
operator|=
name|vec_splat
argument_list|(
name|vsi
argument_list|,
name|idx
argument_list|)
expr_stmt|;
comment|// expected-error {{no matching function}}
comment|// expected-note@vecintrin.h:* 12 {{candidate function not viable}}
comment|// expected-note@vecintrin.h:* 1 {{must be a constant integer from 0 to 3}}
name|vsi
operator|=
name|vec_splat
argument_list|(
name|vsi
argument_list|,
operator|-
literal|1
argument_list|)
expr_stmt|;
comment|// expected-error {{no matching function}}
comment|// expected-note@vecintrin.h:* 12 {{candidate function not viable}}
comment|// expected-note@vecintrin.h:* 1 {{must be a constant integer from 0 to 3}}
name|vsi
operator|=
name|vec_splat
argument_list|(
name|vsi
argument_list|,
literal|4
argument_list|)
expr_stmt|;
comment|// expected-error {{no matching function}}
comment|// expected-note@vecintrin.h:* 12 {{candidate function not viable}}
comment|// expected-note@vecintrin.h:* 1 {{must be a constant integer from 0 to 3}}
name|vui
operator|=
name|vec_splat
argument_list|(
name|vui
argument_list|,
name|idx
argument_list|)
expr_stmt|;
comment|// expected-error {{no matching function}}
comment|// expected-note@vecintrin.h:* 11 {{candidate function not viable}}
comment|// expected-note@vecintrin.h:* 2 {{must be a constant integer from 0 to 3}}
name|vui
operator|=
name|vec_splat
argument_list|(
name|vui
argument_list|,
operator|-
literal|1
argument_list|)
expr_stmt|;
comment|// expected-error {{no matching function}}
comment|// expected-note@vecintrin.h:* 11 {{candidate function not viable}}
comment|// expected-note@vecintrin.h:* 2 {{must be a constant integer from 0 to 3}}
name|vui
operator|=
name|vec_splat
argument_list|(
name|vui
argument_list|,
literal|4
argument_list|)
expr_stmt|;
comment|// expected-error {{no matching function}}
comment|// expected-note@vecintrin.h:* 11 {{candidate function not viable}}
comment|// expected-note@vecintrin.h:* 2 {{must be a constant integer from 0 to 3}}
name|vbi
operator|=
name|vec_splat
argument_list|(
name|vbi
argument_list|,
name|idx
argument_list|)
expr_stmt|;
comment|// expected-error {{no matching function}}
comment|// expected-note@vecintrin.h:* 11 {{candidate function not viable}}
comment|// expected-note@vecintrin.h:* 2 {{must be a constant integer from 0 to 3}}
name|vbi
operator|=
name|vec_splat
argument_list|(
name|vbi
argument_list|,
operator|-
literal|1
argument_list|)
expr_stmt|;
comment|// expected-error {{no matching function}}
comment|// expected-note@vecintrin.h:* 11 {{candidate function not viable}}
comment|// expected-note@vecintrin.h:* 2 {{must be a constant integer from 0 to 3}}
name|vbi
operator|=
name|vec_splat
argument_list|(
name|vbi
argument_list|,
literal|4
argument_list|)
expr_stmt|;
comment|// expected-error {{no matching function}}
comment|// expected-note@vecintrin.h:* 11 {{candidate function not viable}}
comment|// expected-note@vecintrin.h:* 2 {{must be a constant integer from 0 to 3}}
name|vsl
operator|=
name|vec_splat
argument_list|(
name|vsl
argument_list|,
name|idx
argument_list|)
expr_stmt|;
comment|// expected-error {{no matching function}}
comment|// expected-note@vecintrin.h:* 12 {{candidate function not viable}}
comment|// expected-note@vecintrin.h:* 1 {{must be a constant integer from 0 to 1}}
name|vsl
operator|=
name|vec_splat
argument_list|(
name|vsl
argument_list|,
operator|-
literal|1
argument_list|)
expr_stmt|;
comment|// expected-error {{no matching function}}
comment|// expected-note@vecintrin.h:* 12 {{candidate function not viable}}
comment|// expected-note@vecintrin.h:* 1 {{must be a constant integer from 0 to 1}}
name|vsl
operator|=
name|vec_splat
argument_list|(
name|vsl
argument_list|,
literal|2
argument_list|)
expr_stmt|;
comment|// expected-error {{no matching function}}
comment|// expected-note@vecintrin.h:* 12 {{candidate function not viable}}
comment|// expected-note@vecintrin.h:* 1 {{must be a constant integer from 0 to 1}}
name|vul
operator|=
name|vec_splat
argument_list|(
name|vul
argument_list|,
name|idx
argument_list|)
expr_stmt|;
comment|// expected-error {{no matching function}}
comment|// expected-note@vecintrin.h:* 11 {{candidate function not viable}}
comment|// expected-note@vecintrin.h:* 2 {{must be a constant integer from 0 to 1}}
name|vul
operator|=
name|vec_splat
argument_list|(
name|vul
argument_list|,
operator|-
literal|1
argument_list|)
expr_stmt|;
comment|// expected-error {{no matching function}}
comment|// expected-note@vecintrin.h:* 11 {{candidate function not viable}}
comment|// expected-note@vecintrin.h:* 2 {{must be a constant integer from 0 to 1}}
name|vul
operator|=
name|vec_splat
argument_list|(
name|vul
argument_list|,
literal|2
argument_list|)
expr_stmt|;
comment|// expected-error {{no matching function}}
comment|// expected-note@vecintrin.h:* 11 {{candidate function not viable}}
comment|// expected-note@vecintrin.h:* 2 {{must be a constant integer from 0 to 1}}
name|vbl
operator|=
name|vec_splat
argument_list|(
name|vbl
argument_list|,
name|idx
argument_list|)
expr_stmt|;
comment|// expected-error {{no matching function}}
comment|// expected-note@vecintrin.h:* 11 {{candidate function not viable}}
comment|// expected-note@vecintrin.h:* 2 {{must be a constant integer from 0 to 1}}
name|vbl
operator|=
name|vec_splat
argument_list|(
name|vbl
argument_list|,
operator|-
literal|1
argument_list|)
expr_stmt|;
comment|// expected-error {{no matching function}}
comment|// expected-note@vecintrin.h:* 11 {{candidate function not viable}}
comment|// expected-note@vecintrin.h:* 2 {{must be a constant integer from 0 to 1}}
name|vbl
operator|=
name|vec_splat
argument_list|(
name|vbl
argument_list|,
literal|2
argument_list|)
expr_stmt|;
comment|// expected-error {{no matching function}}
comment|// expected-note@vecintrin.h:* 11 {{candidate function not viable}}
comment|// expected-note@vecintrin.h:* 2 {{must be a constant integer from 0 to 1}}
name|vd
operator|=
name|vec_splat
argument_list|(
name|vd
argument_list|,
name|idx
argument_list|)
expr_stmt|;
comment|// expected-error {{no matching function}}
comment|// expected-note@vecintrin.h:* 12 {{candidate function not viable}}
comment|// expected-note@vecintrin.h:* 1 {{must be a constant integer from 0 to 1}}
name|vd
operator|=
name|vec_splat
argument_list|(
name|vd
argument_list|,
operator|-
literal|1
argument_list|)
expr_stmt|;
comment|// expected-error {{no matching function}}
comment|// expected-note@vecintrin.h:* 12 {{candidate function not viable}}
comment|// expected-note@vecintrin.h:* 1 {{must be a constant integer from 0 to 1}}
name|vd
operator|=
name|vec_splat
argument_list|(
name|vd
argument_list|,
literal|2
argument_list|)
expr_stmt|;
comment|// expected-error {{no matching function}}
comment|// expected-note@vecintrin.h:* 12 {{candidate function not viable}}
comment|// expected-note@vecintrin.h:* 1 {{must be a constant integer from 0 to 1}}
name|vsc
operator|=
name|vec_splat_s8
argument_list|(
name|idx
argument_list|)
expr_stmt|;
comment|// expected-error {{no matching function}}
comment|// expected-note@vecintrin.h:* {{must be a constant integer}}
name|vuc
operator|=
name|vec_splat_u8
argument_list|(
name|idx
argument_list|)
expr_stmt|;
comment|// expected-error {{no matching function}}
comment|// expected-note@vecintrin.h:* {{must be a constant integer}}
name|vss
operator|=
name|vec_splat_s16
argument_list|(
name|idx
argument_list|)
expr_stmt|;
comment|// expected-error {{no matching function}}
comment|// expected-note@vecintrin.h:* {{must be a constant integer}}
name|vus
operator|=
name|vec_splat_u16
argument_list|(
name|idx
argument_list|)
expr_stmt|;
comment|// expected-error {{no matching function}}
comment|// expected-note@vecintrin.h:* {{must be a constant integer}}
name|vsi
operator|=
name|vec_splat_s32
argument_list|(
name|idx
argument_list|)
expr_stmt|;
comment|// expected-error {{no matching function}}
comment|// expected-note@vecintrin.h:* {{must be a constant integer}}
name|vui
operator|=
name|vec_splat_u32
argument_list|(
name|idx
argument_list|)
expr_stmt|;
comment|// expected-error {{no matching function}}
comment|// expected-note@vecintrin.h:* {{must be a constant integer}}
name|vsl
operator|=
name|vec_splat_s64
argument_list|(
name|idx
argument_list|)
expr_stmt|;
comment|// expected-error {{no matching function}}
comment|// expected-note@vecintrin.h:* {{must be a constant integer}}
name|vul
operator|=
name|vec_splat_u64
argument_list|(
name|idx
argument_list|)
expr_stmt|;
comment|// expected-error {{no matching function}}
comment|// expected-note@vecintrin.h:* {{must be a constant integer}}
block|}
end_function

begin_function
name|void
name|test_integer
parameter_list|(
name|void
parameter_list|)
block|{
name|vsc
operator|=
name|vec_rl_mask
argument_list|(
name|vsc
argument_list|,
name|vuc
argument_list|,
name|idx
argument_list|)
expr_stmt|;
comment|// expected-error {{no matching function}}
comment|// expected-note@vecintrin.h:* 7 {{candidate function not viable}}
comment|// expected-note@vecintrin.h:* 1 {{must be a constant integer}}
name|vuc
operator|=
name|vec_rl_mask
argument_list|(
name|vuc
argument_list|,
name|vuc
argument_list|,
name|idx
argument_list|)
expr_stmt|;
comment|// expected-error {{no matching function}}
comment|// expected-note@vecintrin.h:* 7 {{candidate function not viable}}
comment|// expected-note@vecintrin.h:* 1 {{must be a constant integer}}
name|vss
operator|=
name|vec_rl_mask
argument_list|(
name|vss
argument_list|,
name|vus
argument_list|,
name|idx
argument_list|)
expr_stmt|;
comment|// expected-error {{no matching function}}
comment|// expected-note@vecintrin.h:* 7 {{candidate function not viable}}
comment|// expected-note@vecintrin.h:* 1 {{must be a constant integer}}
name|vus
operator|=
name|vec_rl_mask
argument_list|(
name|vus
argument_list|,
name|vus
argument_list|,
name|idx
argument_list|)
expr_stmt|;
comment|// expected-error {{no matching function}}
comment|// expected-note@vecintrin.h:* 7 {{candidate function not viable}}
comment|// expected-note@vecintrin.h:* 1 {{must be a constant integer}}
name|vsi
operator|=
name|vec_rl_mask
argument_list|(
name|vsi
argument_list|,
name|vui
argument_list|,
name|idx
argument_list|)
expr_stmt|;
comment|// expected-error {{no matching function}}
comment|// expected-note@vecintrin.h:* 7 {{candidate function not viable}}
comment|// expected-note@vecintrin.h:* 1 {{must be a constant integer}}
name|vui
operator|=
name|vec_rl_mask
argument_list|(
name|vui
argument_list|,
name|vui
argument_list|,
name|idx
argument_list|)
expr_stmt|;
comment|// expected-error {{no matching function}}
comment|// expected-note@vecintrin.h:* 7 {{candidate function not viable}}
comment|// expected-note@vecintrin.h:* 1 {{must be a constant integer}}
name|vsl
operator|=
name|vec_rl_mask
argument_list|(
name|vsl
argument_list|,
name|vul
argument_list|,
name|idx
argument_list|)
expr_stmt|;
comment|// expected-error {{no matching function}}
comment|// expected-note@vecintrin.h:* 7 {{candidate function not viable}}
comment|// expected-note@vecintrin.h:* 1 {{must be a constant integer}}
name|vul
operator|=
name|vec_rl_mask
argument_list|(
name|vul
argument_list|,
name|vul
argument_list|,
name|idx
argument_list|)
expr_stmt|;
comment|// expected-error {{no matching function}}
comment|// expected-note@vecintrin.h:* 7 {{candidate function not viable}}
comment|// expected-note@vecintrin.h:* 1 {{must be a constant integer}}
name|vsc
operator|=
name|vec_sld
argument_list|(
name|vsc
argument_list|,
name|vsc
argument_list|,
name|idx
argument_list|)
expr_stmt|;
comment|// expected-error {{no matching function}}
comment|// expected-note@vecintrin.h:* 12 {{candidate function not viable}}
comment|// expected-note@vecintrin.h:* 1 {{must be a constant integer from 0 to 15}}
name|vsc
operator|=
name|vec_sld
argument_list|(
name|vsc
argument_list|,
name|vsc
argument_list|,
operator|-
literal|1
argument_list|)
expr_stmt|;
comment|// expected-error {{no matching function}}
comment|// expected-note@vecintrin.h:* 12 {{candidate function not viable}}
comment|// expected-note@vecintrin.h:* 1 {{must be a constant integer from 0 to 15}}
name|vsc
operator|=
name|vec_sld
argument_list|(
name|vsc
argument_list|,
name|vsc
argument_list|,
literal|16
argument_list|)
expr_stmt|;
comment|// expected-error {{no matching function}}
comment|// expected-note@vecintrin.h:* 12 {{candidate function not viable}}
comment|// expected-note@vecintrin.h:* 1 {{must be a constant integer from 0 to 15}}
name|vuc
operator|=
name|vec_sld
argument_list|(
name|vuc
argument_list|,
name|vuc
argument_list|,
name|idx
argument_list|)
expr_stmt|;
comment|// expected-error {{no matching function}}
comment|// expected-note@vecintrin.h:* 11 {{candidate function not viable}}
comment|// expected-note@vecintrin.h:* 2 {{must be a constant integer from 0 to 15}}
name|vuc
operator|=
name|vec_sld
argument_list|(
name|vuc
argument_list|,
name|vuc
argument_list|,
operator|-
literal|1
argument_list|)
expr_stmt|;
comment|// expected-error {{no matching function}}
comment|// expected-note@vecintrin.h:* 11 {{candidate function not viable}}
comment|// expected-note@vecintrin.h:* 2 {{must be a constant integer from 0 to 15}}
name|vuc
operator|=
name|vec_sld
argument_list|(
name|vuc
argument_list|,
name|vuc
argument_list|,
literal|16
argument_list|)
expr_stmt|;
comment|// expected-error {{no matching function}}
comment|// expected-note@vecintrin.h:* 11 {{candidate function not viable}}
comment|// expected-note@vecintrin.h:* 2 {{must be a constant integer from 0 to 15}}
name|vss
operator|=
name|vec_sld
argument_list|(
name|vss
argument_list|,
name|vss
argument_list|,
name|idx
argument_list|)
expr_stmt|;
comment|// expected-error {{no matching function}}
comment|// expected-note@vecintrin.h:* 12 {{candidate function not viable}}
comment|// expected-note@vecintrin.h:* 1 {{must be a constant integer from 0 to 15}}
name|vus
operator|=
name|vec_sld
argument_list|(
name|vus
argument_list|,
name|vus
argument_list|,
name|idx
argument_list|)
expr_stmt|;
comment|// expected-error {{no matching function}}
comment|// expected-note@vecintrin.h:* 11 {{candidate function not viable}}
comment|// expected-note@vecintrin.h:* 2 {{must be a constant integer from 0 to 15}}
name|vsi
operator|=
name|vec_sld
argument_list|(
name|vsi
argument_list|,
name|vsi
argument_list|,
name|idx
argument_list|)
expr_stmt|;
comment|// expected-error {{no matching function}}
comment|// expected-note@vecintrin.h:* 12 {{candidate function not viable}}
comment|// expected-note@vecintrin.h:* 1 {{must be a constant integer from 0 to 15}}
name|vui
operator|=
name|vec_sld
argument_list|(
name|vui
argument_list|,
name|vui
argument_list|,
name|idx
argument_list|)
expr_stmt|;
comment|// expected-error {{no matching function}}
comment|// expected-note@vecintrin.h:* 11 {{candidate function not viable}}
comment|// expected-note@vecintrin.h:* 2 {{must be a constant integer from 0 to 15}}
name|vsl
operator|=
name|vec_sld
argument_list|(
name|vsl
argument_list|,
name|vsl
argument_list|,
name|idx
argument_list|)
expr_stmt|;
comment|// expected-error {{no matching function}}
comment|// expected-note@vecintrin.h:* 12 {{candidate function not viable}}
comment|// expected-note@vecintrin.h:* 1 {{must be a constant integer from 0 to 15}}
name|vul
operator|=
name|vec_sld
argument_list|(
name|vul
argument_list|,
name|vul
argument_list|,
name|idx
argument_list|)
expr_stmt|;
comment|// expected-error {{no matching function}}
comment|// expected-note@vecintrin.h:* 11 {{candidate function not viable}}
comment|// expected-note@vecintrin.h:* 2 {{must be a constant integer from 0 to 15}}
name|vd
operator|=
name|vec_sld
argument_list|(
name|vd
argument_list|,
name|vd
argument_list|,
name|idx
argument_list|)
expr_stmt|;
comment|// expected-error {{no matching function}}
comment|// expected-note@vecintrin.h:* 12 {{candidate function not viable}}
comment|// expected-note@vecintrin.h:* 1 {{must be a constant integer from 0 to 15}}
name|vsc
operator|=
name|vec_sldw
argument_list|(
name|vsc
argument_list|,
name|vsc
argument_list|,
name|idx
argument_list|)
expr_stmt|;
comment|// expected-error {{no matching function}}
comment|// expected-note@vecintrin.h:* 8 {{candidate function not viable}}
comment|// expected-note@vecintrin.h:* 1 {{must be a constant integer from 0 to 3}}
name|vsc
operator|=
name|vec_sldw
argument_list|(
name|vsc
argument_list|,
name|vsc
argument_list|,
operator|-
literal|1
argument_list|)
expr_stmt|;
comment|// expected-error {{no matching function}}
comment|// expected-note@vecintrin.h:* 8 {{candidate function not viable}}
comment|// expected-note@vecintrin.h:* 1 {{must be a constant integer from 0 to 3}}
name|vsc
operator|=
name|vec_sldw
argument_list|(
name|vsc
argument_list|,
name|vsc
argument_list|,
literal|4
argument_list|)
expr_stmt|;
comment|// expected-error {{no matching function}}
comment|// expected-note@vecintrin.h:* 8 {{candidate function not viable}}
comment|// expected-note@vecintrin.h:* 1 {{must be a constant integer from 0 to 3}}
name|vuc
operator|=
name|vec_sldw
argument_list|(
name|vuc
argument_list|,
name|vuc
argument_list|,
name|idx
argument_list|)
expr_stmt|;
comment|// expected-error {{no matching function}}
comment|// expected-note@vecintrin.h:* 8 {{candidate function not viable}}
comment|// expected-note@vecintrin.h:* 1 {{must be a constant integer from 0 to 3}}
name|vuc
operator|=
name|vec_sldw
argument_list|(
name|vuc
argument_list|,
name|vuc
argument_list|,
operator|-
literal|1
argument_list|)
expr_stmt|;
comment|// expected-error {{no matching function}}
comment|// expected-note@vecintrin.h:* 8 {{candidate function not viable}}
comment|// expected-note@vecintrin.h:* 1 {{must be a constant integer from 0 to 3}}
name|vuc
operator|=
name|vec_sldw
argument_list|(
name|vuc
argument_list|,
name|vuc
argument_list|,
literal|4
argument_list|)
expr_stmt|;
comment|// expected-error {{no matching function}}
comment|// expected-note@vecintrin.h:* 8 {{candidate function not viable}}
comment|// expected-note@vecintrin.h:* 1 {{must be a constant integer from 0 to 3}}
name|vss
operator|=
name|vec_sldw
argument_list|(
name|vss
argument_list|,
name|vss
argument_list|,
name|idx
argument_list|)
expr_stmt|;
comment|// expected-error {{no matching function}}
comment|// expected-note@vecintrin.h:* 8 {{candidate function not viable}}
comment|// expected-note@vecintrin.h:* 1 {{must be a constant integer from 0 to 3}}
name|vus
operator|=
name|vec_sldw
argument_list|(
name|vus
argument_list|,
name|vus
argument_list|,
name|idx
argument_list|)
expr_stmt|;
comment|// expected-error {{no matching function}}
comment|// expected-note@vecintrin.h:* 8 {{candidate function not viable}}
comment|// expected-note@vecintrin.h:* 1 {{must be a constant integer from 0 to 3}}
name|vsi
operator|=
name|vec_sldw
argument_list|(
name|vsi
argument_list|,
name|vsi
argument_list|,
name|idx
argument_list|)
expr_stmt|;
comment|// expected-error {{no matching function}}
comment|// expected-note@vecintrin.h:* 8 {{candidate function not viable}}
comment|// expected-note@vecintrin.h:* 1 {{must be a constant integer from 0 to 3}}
name|vui
operator|=
name|vec_sldw
argument_list|(
name|vui
argument_list|,
name|vui
argument_list|,
name|idx
argument_list|)
expr_stmt|;
comment|// expected-error {{no matching function}}
comment|// expected-note@vecintrin.h:* 8 {{candidate function not viable}}
comment|// expected-note@vecintrin.h:* 1 {{must be a constant integer from 0 to 3}}
name|vsl
operator|=
name|vec_sldw
argument_list|(
name|vsl
argument_list|,
name|vsl
argument_list|,
name|idx
argument_list|)
expr_stmt|;
comment|// expected-error {{no matching function}}
comment|// expected-note@vecintrin.h:* 8 {{candidate function not viable}}
comment|// expected-note@vecintrin.h:* 1 {{must be a constant integer from 0 to 3}}
name|vul
operator|=
name|vec_sldw
argument_list|(
name|vul
argument_list|,
name|vul
argument_list|,
name|idx
argument_list|)
expr_stmt|;
comment|// expected-error {{no matching function}}
comment|// expected-note@vecintrin.h:* 8 {{candidate function not viable}}
comment|// expected-note@vecintrin.h:* 1 {{must be a constant integer from 0 to 3}}
name|vd
operator|=
name|vec_sldw
argument_list|(
name|vd
argument_list|,
name|vd
argument_list|,
name|idx
argument_list|)
expr_stmt|;
comment|// expected-error {{no matching function}}
comment|// expected-note@vecintrin.h:* 8 {{candidate function not viable}}
comment|// expected-note@vecintrin.h:* 1 {{must be a constant integer from 0 to 3}}
block|}
end_function

begin_function
name|void
name|test_float
parameter_list|(
name|void
parameter_list|)
block|{
name|vd
operator|=
name|vec_ctd
argument_list|(
name|vsl
argument_list|,
name|idx
argument_list|)
expr_stmt|;
comment|// expected-error {{no matching function}}
comment|// expected-note@vecintrin.h:* 1 {{candidate function not viable}}
comment|// expected-note@vecintrin.h:* 1 {{must be a constant integer from 0 to 31}}
name|vd
operator|=
name|vec_ctd
argument_list|(
name|vsl
argument_list|,
operator|-
literal|1
argument_list|)
expr_stmt|;
comment|// expected-error {{no matching function}}
comment|// expected-note@vecintrin.h:* 1 {{candidate function not viable}}
comment|// expected-note@vecintrin.h:* 1 {{must be a constant integer from 0 to 31}}
name|vd
operator|=
name|vec_ctd
argument_list|(
name|vsl
argument_list|,
literal|32
argument_list|)
expr_stmt|;
comment|// expected-error {{no matching function}}
comment|// expected-note@vecintrin.h:* 1 {{candidate function not viable}}
comment|// expected-note@vecintrin.h:* 1 {{must be a constant integer from 0 to 31}}
name|vd
operator|=
name|vec_ctd
argument_list|(
name|vul
argument_list|,
name|idx
argument_list|)
expr_stmt|;
comment|// expected-error {{no matching function}}
comment|// expected-note@vecintrin.h:* 1 {{candidate function not viable}}
comment|// expected-note@vecintrin.h:* 1 {{must be a constant integer from 0 to 31}}
name|vd
operator|=
name|vec_ctd
argument_list|(
name|vul
argument_list|,
operator|-
literal|1
argument_list|)
expr_stmt|;
comment|// expected-error {{no matching function}}
comment|// expected-note@vecintrin.h:* 1 {{candidate function not viable}}
comment|// expected-note@vecintrin.h:* 1 {{must be a constant integer from 0 to 31}}
name|vd
operator|=
name|vec_ctd
argument_list|(
name|vul
argument_list|,
literal|32
argument_list|)
expr_stmt|;
comment|// expected-error {{no matching function}}
comment|// expected-note@vecintrin.h:* 1 {{candidate function not viable}}
comment|// expected-note@vecintrin.h:* 1 {{must be a constant integer from 0 to 31}}
name|vsl
operator|=
name|vec_ctsl
argument_list|(
name|vd
argument_list|,
name|idx
argument_list|)
expr_stmt|;
comment|// expected-error {{no matching function}}
comment|// expected-note@vecintrin.h:* 1 {{must be a constant integer from 0 to 31}}
name|vsl
operator|=
name|vec_ctsl
argument_list|(
name|vd
argument_list|,
operator|-
literal|1
argument_list|)
expr_stmt|;
comment|// expected-error {{no matching function}}
comment|// expected-note@vecintrin.h:* 1 {{must be a constant integer from 0 to 31}}
name|vsl
operator|=
name|vec_ctsl
argument_list|(
name|vd
argument_list|,
literal|32
argument_list|)
expr_stmt|;
comment|// expected-error {{no matching function}}
comment|// expected-note@vecintrin.h:* 1 {{must be a constant integer from 0 to 31}}
name|vul
operator|=
name|vec_ctul
argument_list|(
name|vd
argument_list|,
name|idx
argument_list|)
expr_stmt|;
comment|// expected-error {{no matching function}}
comment|// expected-note@vecintrin.h:* 1 {{must be a constant integer from 0 to 31}}
name|vul
operator|=
name|vec_ctul
argument_list|(
name|vd
argument_list|,
operator|-
literal|1
argument_list|)
expr_stmt|;
comment|// expected-error {{no matching function}}
comment|// expected-note@vecintrin.h:* 1 {{must be a constant integer from 0 to 31}}
name|vul
operator|=
name|vec_ctul
argument_list|(
name|vd
argument_list|,
literal|32
argument_list|)
expr_stmt|;
comment|// expected-error {{no matching function}}
comment|// expected-note@vecintrin.h:* 1 {{must be a constant integer from 0 to 31}}
name|vbl
operator|=
name|vec_fp_test_data_class
argument_list|(
name|vd
argument_list|,
name|idx
argument_list|,
operator|&
name|cc
argument_list|)
expr_stmt|;
comment|// expected-error {{must be a constant integer}}
name|vbl
operator|=
name|vec_fp_test_data_class
argument_list|(
name|vd
argument_list|,
operator|-
literal|1
argument_list|,
operator|&
name|cc
argument_list|)
expr_stmt|;
comment|// expected-error {{should be a value from 0 to 4095}}
name|vbl
operator|=
name|vec_fp_test_data_class
argument_list|(
name|vd
argument_list|,
literal|4096
argument_list|,
operator|&
name|cc
argument_list|)
expr_stmt|;
comment|// expected-error {{should be a value from 0 to 4095}}
block|}
end_function

end_unit

