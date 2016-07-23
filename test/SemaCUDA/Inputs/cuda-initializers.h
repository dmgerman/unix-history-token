begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// CUDA struct types with interesting initialization properties.
end_comment

begin_comment
comment|// Keep in sync with ../CodeGenCUDA/Inputs/cuda-initializers.h.
end_comment

begin_comment
comment|// Base classes with different initializer variants.
end_comment

begin_comment
comment|// trivial constructor -- allowed
end_comment

begin_struct
struct|struct
name|T
block|{
name|int
name|t
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|// empty constructor
end_comment

begin_struct
struct|struct
name|EC
block|{
name|int
name|ec
decl_stmt|;
name|__device__
name|EC
parameter_list|()
block|{}
comment|// -- allowed
name|__device__
name|EC
parameter_list|(
name|int
parameter_list|)
block|{}
comment|// -- not allowed
block|}
struct|;
end_struct

begin_comment
comment|// empty destructor
end_comment

begin_struct
struct|struct
name|ED
block|{
name|__device__
operator|~
name|ED
argument_list|()
block|{}
comment|// -- allowed
block|}
struct|;
end_struct

begin_struct
struct|struct
name|ECD
block|{
name|__device__
name|ECD
parameter_list|()
block|{}
comment|// -- allowed
name|__device__
operator|~
name|ECD
argument_list|()
block|{}
comment|// -- allowed
block|}
struct|;
end_struct

begin_comment
comment|// empty templated constructor -- allowed with no arguments
end_comment

begin_struct
struct|struct
name|ETC
block|{
name|template
operator|<
name|typename
operator|...
name|T
operator|>
name|__device__
name|ETC
argument_list|(
argument|T...
argument_list|)
block|{}
block|}
struct|;
end_struct

begin_comment
comment|// undefined constructor -- not allowed
end_comment

begin_struct
struct|struct
name|UC
block|{
name|int
name|uc
decl_stmt|;
name|__device__
name|UC
parameter_list|()
function_decl|;
block|}
struct|;
end_struct

begin_comment
comment|// undefined destructor -- not allowed
end_comment

begin_struct
struct|struct
name|UD
block|{
name|int
name|ud
decl_stmt|;
name|__device__
operator|~
name|UD
argument_list|()
expr_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|// empty constructor w/ initializer list -- not allowed
end_comment

begin_struct
struct|struct
name|ECI
block|{
name|int
name|eci
decl_stmt|;
name|__device__
name|ECI
argument_list|()
operator|:
name|eci
argument_list|(
literal|1
argument_list|)
block|{}
block|}
struct|;
end_struct

begin_comment
comment|// non-empty constructor -- not allowed
end_comment

begin_struct
struct|struct
name|NEC
block|{
name|int
name|nec
decl_stmt|;
name|__device__
name|NEC
parameter_list|()
block|{
name|nec
operator|=
literal|1
expr_stmt|;
block|}
block|}
struct|;
end_struct

begin_comment
comment|// non-empty destructor -- not allowed
end_comment

begin_struct
struct|struct
name|NED
block|{
name|int
name|ned
decl_stmt|;
name|__device__
operator|~
name|NED
argument_list|()
block|{
name|ned
operator|=
literal|1
block|; }
block|}
struct|;
end_struct

begin_comment
comment|// no-constructor,  virtual method -- not allowed
end_comment

begin_struct
struct|struct
name|NCV
block|{
name|int
name|ncv
decl_stmt|;
name|__device__
name|virtual
name|void
name|vm
parameter_list|()
block|{}
block|}
struct|;
end_struct

begin_comment
comment|// virtual destructor -- not allowed.
end_comment

begin_struct
struct|struct
name|VD
block|{
name|__device__
name|virtual
operator|~
name|VD
argument_list|()
block|{}
block|}
struct|;
end_struct

begin_comment
comment|// dynamic in-class field initializer -- not allowed
end_comment

begin_function_decl
name|__device__
name|int
name|f
parameter_list|()
function_decl|;
end_function_decl

begin_struct
struct|struct
name|NCF
block|{
name|int
name|ncf
init|=
name|f
argument_list|()
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|// static in-class field initializer.  NVCC does not allow it, but
end_comment

begin_comment
comment|// clang generates static initializer for this, so we'll accept it.
end_comment

begin_comment
comment|// We still can't use it on __shared__ vars as they don't allow *any*
end_comment

begin_comment
comment|// initializers.
end_comment

begin_struct
struct|struct
name|NCFS
block|{
name|int
name|ncfs
init|=
literal|3
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|// undefined templated constructor -- not allowed
end_comment

begin_struct
struct|struct
name|UTC
block|{
name|template
operator|<
name|typename
operator|...
name|T
operator|>
name|__device__
name|UTC
argument_list|(
name|T
operator|...
argument_list|)
expr_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|// non-empty templated constructor -- not allowed
end_comment

begin_struct
struct|struct
name|NETC
block|{
name|int
name|netc
decl_stmt|;
name|template
operator|<
name|typename
operator|...
name|T
operator|>
name|__device__
name|NETC
argument_list|(
argument|T...
argument_list|)
block|{
name|netc
operator|=
literal|1
block|; }
block|}
struct|;
end_struct

begin_comment
comment|// Regular base class -- allowed
end_comment

begin_decl_stmt
name|struct
name|T_B_T
range|:
name|T
block|{}
decl_stmt|;
end_decl_stmt

begin_comment
comment|// Incapsulated object of allowed class -- allowed
end_comment

begin_struct
struct|struct
name|T_F_T
block|{
name|T
name|t
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|// array of allowed objects -- allowed
end_comment

begin_struct
struct|struct
name|T_FA_T
block|{
name|T
name|t
index|[
literal|2
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|// Calling empty base class initializer is OK
end_comment

begin_decl_stmt
name|struct
name|EC_I_EC
range|:
name|EC
block|{
name|__device__
name|EC_I_EC
argument_list|()
operator|:
name|EC
argument_list|()
block|{}
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|// .. though passing arguments is not allowed.
end_comment

begin_decl_stmt
name|struct
name|EC_I_EC1
range|:
name|EC
block|{
name|__device__
name|EC_I_EC1
argument_list|()
operator|:
name|EC
argument_list|(
literal|1
argument_list|)
block|{}
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|// Virtual base class -- not allowed
end_comment

begin_decl_stmt
name|struct
name|T_V_T
range|:
name|virtual
name|T
block|{}
decl_stmt|;
end_decl_stmt

begin_comment
comment|// Inherited from or incapsulated class with non-empty constructor --
end_comment

begin_comment
comment|// not allowed
end_comment

begin_decl_stmt
name|struct
name|T_B_NEC
range|:
name|NEC
block|{}
decl_stmt|;
end_decl_stmt

begin_struct
struct|struct
name|T_F_NEC
block|{
name|NEC
name|nec
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|T_FA_NEC
block|{
name|NEC
name|nec
index|[
literal|2
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|// Inherited from or incapsulated class with non-empty desstructor --
end_comment

begin_comment
comment|// not allowed
end_comment

begin_decl_stmt
name|struct
name|T_B_NED
range|:
name|NED
block|{}
decl_stmt|;
end_decl_stmt

begin_struct
struct|struct
name|T_F_NED
block|{
name|NED
name|ned
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|T_FA_NED
block|{
name|NED
name|ned
index|[
literal|2
index|]
decl_stmt|;
block|}
struct|;
end_struct

end_unit

