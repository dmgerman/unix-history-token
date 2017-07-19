begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// REQUIRES: systemz-registered-target
end_comment

begin_comment
comment|// RUN: %clang_cc1 -target-cpu z14 -triple s390x-unknown-unknown \
end_comment

begin_comment
comment|// RUN: -Wall -Wno-unused -Werror -fsyntax-only -verify %s
end_comment

begin_typedef
typedef|typedef
name|__attribute__
argument_list|(
argument|(vector_size(
literal|16
argument|))
argument_list|)
name|signed
name|char
name|vec_schar
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|__attribute__
argument_list|(
argument|(vector_size(
literal|16
argument|))
argument_list|)
name|signed
name|short
name|vec_sshort
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|__attribute__
argument_list|(
argument|(vector_size(
literal|16
argument|))
argument_list|)
name|signed
name|int
name|vec_sint
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|__attribute__
argument_list|(
argument|(vector_size(
literal|16
argument|))
argument_list|)
name|signed
name|long
name|long
name|vec_slong
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|__attribute__
argument_list|(
argument|(vector_size(
literal|16
argument|))
argument_list|)
name|unsigned
name|char
name|vec_uchar
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|__attribute__
argument_list|(
argument|(vector_size(
literal|16
argument|))
argument_list|)
name|unsigned
name|short
name|vec_ushort
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|__attribute__
argument_list|(
argument|(vector_size(
literal|16
argument|))
argument_list|)
name|unsigned
name|int
name|vec_uint
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|__attribute__
argument_list|(
argument|(vector_size(
literal|16
argument|))
argument_list|)
name|unsigned
name|long
name|long
name|vec_ulong
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|__attribute__
argument_list|(
argument|(vector_size(
literal|16
argument|))
argument_list|)
name|double
name|vec_double
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|__attribute__
argument_list|(
argument|(vector_size(
literal|16
argument|))
argument_list|)
name|float
name|vec_float
typedef|;
end_typedef

begin_decl_stmt
specifier|volatile
name|vec_schar
name|vsc
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|volatile
name|vec_sshort
name|vss
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|volatile
name|vec_sint
name|vsi
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|volatile
name|vec_slong
name|vsl
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|volatile
name|vec_uchar
name|vuc
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|volatile
name|vec_ushort
name|vus
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|volatile
name|vec_uint
name|vui
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|volatile
name|vec_ulong
name|vul
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|volatile
name|vec_double
name|vd
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|volatile
name|vec_float
name|vf
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
name|int
name|cc
decl_stmt|;
end_decl_stmt

begin_function
name|void
name|test_integer
parameter_list|(
name|void
parameter_list|)
block|{
name|__builtin_s390_vmslg
argument_list|(
name|vul
argument_list|,
name|vul
argument_list|,
name|vuc
argument_list|,
operator|-
literal|1
argument_list|)
expr_stmt|;
comment|// expected-error {{argument should be a value from 0 to 15}}
name|__builtin_s390_vmslg
argument_list|(
name|vul
argument_list|,
name|vul
argument_list|,
name|vuc
argument_list|,
literal|16
argument_list|)
expr_stmt|;
comment|// expected-error {{argument should be a value from 0 to 15}}
name|__builtin_s390_vmslg
argument_list|(
name|vul
argument_list|,
name|vul
argument_list|,
name|vuc
argument_list|,
name|len
argument_list|)
expr_stmt|;
comment|// expected-error {{must be a constant integer}}
block|}
end_function

begin_function
name|void
name|test_float
parameter_list|(
name|void
parameter_list|)
block|{
name|__builtin_s390_vfmaxdb
argument_list|(
name|vd
argument_list|,
name|vd
argument_list|,
operator|-
literal|1
argument_list|)
expr_stmt|;
comment|// expected-error {{argument should be a value from 0 to 15}}
name|__builtin_s390_vfmaxdb
argument_list|(
name|vd
argument_list|,
name|vd
argument_list|,
literal|16
argument_list|)
expr_stmt|;
comment|// expected-error {{argument should be a value from 0 to 15}}
name|__builtin_s390_vfmaxdb
argument_list|(
name|vd
argument_list|,
name|vd
argument_list|,
name|len
argument_list|)
expr_stmt|;
comment|// expected-error {{must be a constant integer}}
name|__builtin_s390_vfmindb
argument_list|(
name|vd
argument_list|,
name|vd
argument_list|,
operator|-
literal|1
argument_list|)
expr_stmt|;
comment|// expected-error {{argument should be a value from 0 to 15}}
name|__builtin_s390_vfmindb
argument_list|(
name|vd
argument_list|,
name|vd
argument_list|,
literal|16
argument_list|)
expr_stmt|;
comment|// expected-error {{argument should be a value from 0 to 15}}
name|__builtin_s390_vfmindb
argument_list|(
name|vd
argument_list|,
name|vd
argument_list|,
name|len
argument_list|)
expr_stmt|;
comment|// expected-error {{must be a constant integer}}
name|__builtin_s390_vftcisb
argument_list|(
name|vf
argument_list|,
operator|-
literal|1
argument_list|,
operator|&
name|cc
argument_list|)
expr_stmt|;
comment|// expected-error {{argument should be a value from 0 to 4095}}
name|__builtin_s390_vftcisb
argument_list|(
name|vf
argument_list|,
literal|4096
argument_list|,
operator|&
name|cc
argument_list|)
expr_stmt|;
comment|// expected-error {{argument should be a value from 0 to 4095}}
name|__builtin_s390_vftcisb
argument_list|(
name|vf
argument_list|,
name|len
argument_list|,
operator|&
name|cc
argument_list|)
expr_stmt|;
comment|// expected-error {{must be a constant integer}}
name|__builtin_s390_vfisb
argument_list|(
name|vf
argument_list|,
operator|-
literal|1
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// expected-error {{argument should be a value from 0 to 15}}
name|__builtin_s390_vfisb
argument_list|(
name|vf
argument_list|,
literal|16
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// expected-error {{argument should be a value from 0 to 15}}
name|__builtin_s390_vfisb
argument_list|(
name|vf
argument_list|,
name|len
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// expected-error {{must be a constant integer}}
name|__builtin_s390_vfisb
argument_list|(
name|vf
argument_list|,
literal|0
argument_list|,
operator|-
literal|1
argument_list|)
expr_stmt|;
comment|// expected-error {{argument should be a value from 0 to 15}}
name|__builtin_s390_vfisb
argument_list|(
name|vf
argument_list|,
literal|0
argument_list|,
literal|16
argument_list|)
expr_stmt|;
comment|// expected-error {{argument should be a value from 0 to 15}}
name|__builtin_s390_vfisb
argument_list|(
name|vf
argument_list|,
literal|0
argument_list|,
name|len
argument_list|)
expr_stmt|;
comment|// expected-error {{must be a constant integer}}
name|__builtin_s390_vfmaxsb
argument_list|(
name|vf
argument_list|,
name|vf
argument_list|,
operator|-
literal|1
argument_list|)
expr_stmt|;
comment|// expected-error {{argument should be a value from 0 to 15}}
name|__builtin_s390_vfmaxsb
argument_list|(
name|vf
argument_list|,
name|vf
argument_list|,
literal|16
argument_list|)
expr_stmt|;
comment|// expected-error {{argument should be a value from 0 to 15}}
name|__builtin_s390_vfmaxsb
argument_list|(
name|vf
argument_list|,
name|vf
argument_list|,
name|len
argument_list|)
expr_stmt|;
comment|// expected-error {{must be a constant integer}}
name|__builtin_s390_vfminsb
argument_list|(
name|vf
argument_list|,
name|vf
argument_list|,
operator|-
literal|1
argument_list|)
expr_stmt|;
comment|// expected-error {{argument should be a value from 0 to 15}}
name|__builtin_s390_vfminsb
argument_list|(
name|vf
argument_list|,
name|vf
argument_list|,
literal|16
argument_list|)
expr_stmt|;
comment|// expected-error {{argument should be a value from 0 to 15}}
name|__builtin_s390_vfminsb
argument_list|(
name|vf
argument_list|,
name|vf
argument_list|,
name|len
argument_list|)
expr_stmt|;
comment|// expected-error {{must be a constant integer}}
block|}
end_function

end_unit

