begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_define
define|#
directive|define
name|__extension__
end_define

begin_define
define|#
directive|define
name|__stpcpy
parameter_list|(
name|dest
parameter_list|,
name|src
parameter_list|)
value|(__extension__ (__builtin_constant_p (src) ? (__string2_1bptr_p (src)&& strlen (src) + 1<= 8 ? __stpcpy_small (dest, __stpcpy_args (src), strlen (src) + 1) : ((char *) __mempcpy (dest, src, strlen (src) + 1) - 1)) : __stpcpy (dest, src)))
end_define

begin_define
define|#
directive|define
name|stpcpy
parameter_list|(
name|dest
parameter_list|,
name|src
parameter_list|)
value|__stpcpy (dest, src)
end_define

begin_define
define|#
directive|define
name|__stpcpy_args
parameter_list|(
name|src
parameter_list|)
value|__extension__ __STRING2_SMALL_GET16 (src, 0), __extension__ __STRING2_SMALL_GET16 (src, 4), __extension__ __STRING2_SMALL_GET32 (src, 0), __extension__ __STRING2_SMALL_GET32 (src, 4)
end_define

begin_define
define|#
directive|define
name|__mempcpy
parameter_list|(
name|dest
parameter_list|,
name|src
parameter_list|,
name|n
parameter_list|)
value|(__extension__ (__builtin_constant_p (src)&& __builtin_constant_p (n)&& __string2_1bptr_p (src)&& n<= 8 ? __mempcpy_small (dest, __mempcpy_args (src), n) : __mempcpy (dest, src, n)))
end_define

begin_define
define|#
directive|define
name|mempcpy
parameter_list|(
name|dest
parameter_list|,
name|src
parameter_list|,
name|n
parameter_list|)
value|__mempcpy (dest, src, n)
end_define

begin_define
define|#
directive|define
name|__mempcpy_args
parameter_list|(
name|src
parameter_list|)
value|((char *) (src))[0], ((char *) (src))[2], ((char *) (src))[4], ((char *) (src))[6], __extension__ __STRING2_SMALL_GET16 (src, 0), __extension__ __STRING2_SMALL_GET16 (src, 4), __extension__ __STRING2_SMALL_GET32 (src, 0), __extension__ __STRING2_SMALL_GET32 (src, 4)
end_define

begin_define
define|#
directive|define
name|__STRING2_SMALL_GET16
parameter_list|(
name|src
parameter_list|,
name|idx
parameter_list|)
value|(((__const unsigned char *) (__const char *) (src))[idx + 1]<< 8 | ((__const unsigned char *) (__const char *) (src))[idx])
end_define

begin_define
define|#
directive|define
name|__STRING2_SMALL_GET32
parameter_list|(
name|src
parameter_list|,
name|idx
parameter_list|)
value|(((((__const unsigned char *) (__const char *) (src))[idx + 3]<< 8 | ((__const unsigned char *) (__const char *) (src))[idx + 2])<< 8 | ((__const unsigned char *) (__const char *) (src))[idx + 1])<< 8 | ((__const unsigned char *) (__const char *) (src))[idx])
end_define

begin_macro
name|stpcpy
argument_list|(
argument|stpcpy (stpcpy (stpcpy (a, b), c), d)
argument_list|,
argument|e
argument_list|)
end_macro

begin_macro
name|stpcpy
argument_list|(
argument|stpcpy (stpcpy (stpcpy (a, b), c), d)
argument_list|,
argument|e
argument_list|)
end_macro

begin_macro
name|stpcpy
argument_list|(
argument|stpcpy (stpcpy (stpcpy (a, b), c), d)
argument_list|,
argument|e
argument_list|)
end_macro

begin_macro
name|stpcpy
argument_list|(
argument|stpcpy (stpcpy (stpcpy (a, b), c), d)
argument_list|,
argument|e
argument_list|)
end_macro

begin_macro
name|stpcpy
argument_list|(
argument|stpcpy (stpcpy (stpcpy (a, b), c), d)
argument_list|,
argument|e
argument_list|)
end_macro

begin_macro
name|stpcpy
argument_list|(
argument|stpcpy (stpcpy (stpcpy (a, b), c), d)
argument_list|,
argument|e
argument_list|)
end_macro

begin_macro
name|stpcpy
argument_list|(
argument|stpcpy (stpcpy (stpcpy (a, b), c), d)
argument_list|,
argument|e
argument_list|)
end_macro

begin_macro
name|stpcpy
argument_list|(
argument|stpcpy (stpcpy (stpcpy (a, b), c), d)
argument_list|,
argument|e
argument_list|)
end_macro

begin_macro
name|stpcpy
argument_list|(
argument|stpcpy (stpcpy (stpcpy (a, b), c), d)
argument_list|,
argument|e
argument_list|)
end_macro

begin_macro
name|stpcpy
argument_list|(
argument|stpcpy (stpcpy (stpcpy (a, b), c), d)
argument_list|,
argument|e
argument_list|)
end_macro

begin_macro
name|stpcpy
argument_list|(
argument|stpcpy (stpcpy (stpcpy (a, b), c), d)
argument_list|,
argument|e
argument_list|)
end_macro

begin_macro
name|stpcpy
argument_list|(
argument|stpcpy (stpcpy (stpcpy (a, b), c), d)
argument_list|,
argument|e
argument_list|)
end_macro

begin_macro
name|stpcpy
argument_list|(
argument|stpcpy (stpcpy (stpcpy (a, b), c), d)
argument_list|,
argument|e
argument_list|)
end_macro

begin_macro
name|stpcpy
argument_list|(
argument|stpcpy (stpcpy (stpcpy (a, b), c), d)
argument_list|,
argument|e
argument_list|)
end_macro

begin_macro
name|stpcpy
argument_list|(
argument|stpcpy (stpcpy (stpcpy (a, b), c), d)
argument_list|,
argument|e
argument_list|)
end_macro

begin_macro
name|stpcpy
argument_list|(
argument|stpcpy (stpcpy (stpcpy (a, b), c), d)
argument_list|,
argument|e
argument_list|)
end_macro

begin_macro
name|stpcpy
argument_list|(
argument|stpcpy (stpcpy (stpcpy (a, b), c), d)
argument_list|,
argument|e
argument_list|)
end_macro

begin_macro
name|stpcpy
argument_list|(
argument|stpcpy (stpcpy (stpcpy (a, b), c), d)
argument_list|,
argument|e
argument_list|)
end_macro

begin_macro
name|stpcpy
argument_list|(
argument|stpcpy (stpcpy (stpcpy (a, b), c), d)
argument_list|,
argument|e
argument_list|)
end_macro

begin_macro
name|stpcpy
argument_list|(
argument|stpcpy (stpcpy (stpcpy (a, b), c), d)
argument_list|,
argument|e
argument_list|)
end_macro

begin_macro
name|stpcpy
argument_list|(
argument|stpcpy (stpcpy (stpcpy (a, b), c), d)
argument_list|,
argument|e
argument_list|)
end_macro

begin_macro
name|stpcpy
argument_list|(
argument|stpcpy (stpcpy (stpcpy (a, b), c), d)
argument_list|,
argument|e
argument_list|)
end_macro

begin_macro
name|stpcpy
argument_list|(
argument|stpcpy (stpcpy (stpcpy (a, b), c), d)
argument_list|,
argument|e
argument_list|)
end_macro

begin_macro
name|stpcpy
argument_list|(
argument|stpcpy (stpcpy (stpcpy (a, b), c), d)
argument_list|,
argument|e
argument_list|)
end_macro

begin_macro
name|stpcpy
argument_list|(
argument|stpcpy (stpcpy (stpcpy (a, b), c), d)
argument_list|,
argument|e
argument_list|)
end_macro

begin_macro
name|stpcpy
argument_list|(
argument|stpcpy (stpcpy (stpcpy (a, b), c), d)
argument_list|,
argument|e
argument_list|)
end_macro

begin_macro
name|stpcpy
argument_list|(
argument|stpcpy (stpcpy (stpcpy (a, b), c), d)
argument_list|,
argument|e
argument_list|)
end_macro

begin_macro
name|stpcpy
argument_list|(
argument|stpcpy (stpcpy (stpcpy (a, b), c), d)
argument_list|,
argument|e
argument_list|)
end_macro

begin_macro
name|stpcpy
argument_list|(
argument|stpcpy (stpcpy (stpcpy (a, b), c), d)
argument_list|,
argument|e
argument_list|)
end_macro

begin_macro
name|stpcpy
argument_list|(
argument|stpcpy (stpcpy (stpcpy (a, b), c), d)
argument_list|,
argument|e
argument_list|)
end_macro

begin_macro
name|stpcpy
argument_list|(
argument|stpcpy (stpcpy (stpcpy (a, b), c), d)
argument_list|,
argument|e
argument_list|)
end_macro

begin_macro
name|stpcpy
argument_list|(
argument|stpcpy (stpcpy (stpcpy (a, b), c), d)
argument_list|,
argument|e
argument_list|)
end_macro

begin_macro
name|stpcpy
argument_list|(
argument|stpcpy (stpcpy (stpcpy (a, b), c), d)
argument_list|,
argument|e
argument_list|)
end_macro

end_unit

