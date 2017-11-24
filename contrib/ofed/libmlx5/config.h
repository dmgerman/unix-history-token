begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_define
define|#
directive|define
name|min_t
parameter_list|(
name|type
parameter_list|,
name|x
parameter_list|,
name|y
parameter_list|)
value|({			\ 	type __min1 = (x);			\ 	type __min2 = (y);			\ 	__min1< __min2 ? __min1 : __min2; })
end_define

begin_define
define|#
directive|define
name|max_t
parameter_list|(
name|type
parameter_list|,
name|x
parameter_list|,
name|y
parameter_list|)
value|({			\ 	type __max1 = (x);			\ 	type __max2 = (y);			\ 	__max1> __max2 ? __max1 : __max2; })
end_define

begin_define
define|#
directive|define
name|min
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|((a)> (b) ? (b) : (a))
end_define

begin_define
define|#
directive|define
name|max
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|((a)< (b) ? (b) : (a))
end_define

begin_define
define|#
directive|define
name|SWITCH_FALLTHROUGH
value|(void)0
end_define

begin_define
define|#
directive|define
name|ALWAYS_INLINE
value|__attribute__ ((__always_inline__))
end_define

begin_define
define|#
directive|define
name|VALGRIND_MAKE_MEM_DEFINED
parameter_list|(
modifier|...
parameter_list|)
value|0
end_define

begin_define
define|#
directive|define
name|likely
parameter_list|(
name|x
parameter_list|)
value|__predict_true(x)
end_define

begin_define
define|#
directive|define
name|unlikely
parameter_list|(
name|x
parameter_list|)
value|__predict_false(x)
end_define

begin_define
define|#
directive|define
name|SHM_HUGETLB
value|0
end_define

end_unit

