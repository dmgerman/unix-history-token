begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Public domain.  */
end_comment

begin_typedef
typedef|typedef
name|unsigned
name|int
name|USItype
name|__attribute__
typedef|((
name|mode
typedef|(
name|SI
typedef|)));
end_typedef

begin_typedef
typedef|typedef
name|int
name|SItype
name|__attribute__
typedef|((
name|mode
typedef|(
name|SI
typedef|)));
end_typedef

begin_typedef
typedef|typedef
name|float
name|SFtype
name|__attribute__
typedef|((
name|mode
typedef|(
name|SF
typedef|)));
end_typedef

begin_function_decl
name|USItype
name|__fixunssfsi
parameter_list|(
name|SFtype
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|SItype_MIN
define|\
value|(- ((SItype) (((USItype) 1<< ((sizeof (SItype) * 8) - 1)) - 1)) - 1)
end_define

begin_function
name|USItype
name|__fixunssfsi
parameter_list|(
name|SFtype
name|a
parameter_list|)
block|{
if|if
condition|(
name|a
operator|>=
operator|-
operator|(
name|SFtype
operator|)
name|SItype_MIN
condition|)
return|return
call|(
name|SItype
call|)
argument_list|(
name|a
operator|+
name|SItype_MIN
argument_list|)
operator|-
name|SItype_MIN
return|;
return|return
operator|(
name|SItype
operator|)
name|a
return|;
block|}
end_function

end_unit

