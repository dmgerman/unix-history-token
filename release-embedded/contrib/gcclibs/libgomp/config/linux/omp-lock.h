begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* This header is used during the build process to find the size and     alignment of the public OpenMP locks, so that we can export data    structures without polluting the namespace.     When using the Linux futex primitive, non-recursive locks require    only one int.  Recursive locks require we identify the owning thread    and so require two ints.  */
end_comment

begin_typedef
typedef|typedef
name|int
name|omp_lock_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|int
name|owner
decl_stmt|,
name|count
decl_stmt|;
block|}
name|omp_nest_lock_t
typedef|;
end_typedef

end_unit

