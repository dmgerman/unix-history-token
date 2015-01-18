begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// override-system-header.h to test out 'override' warning.
end_comment

begin_comment
comment|// rdar://18295240
end_comment

begin_define
define|#
directive|define
name|END_COM_MAP
value|virtual unsigned AddRef(void) = 0;
end_define

begin_define
define|#
directive|define
name|STDMETHOD
parameter_list|(
name|method
parameter_list|)
value|virtual void method
end_define

begin_define
define|#
directive|define
name|IFACEMETHOD
parameter_list|(
name|method
parameter_list|)
value|STDMETHOD(method)
end_define

end_unit

