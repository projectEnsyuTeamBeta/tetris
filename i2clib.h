#ifndef I2CLIB_H
#define I2CLIB_H

extern	void initI2C(void);
extern	short sci_i2c_master_send(unsigned char const*data, unsigned char num,
								  unsigned char slave_add);
extern	short sci_i2c_master_recv(unsigned char*data, unsigned char num,
								  unsigned char slave_add);
extern	short sci_i2c_master_sendrecv(unsigned char const* Wdata,
								  unsigned char Wnum, unsigned char* Rdata,
								  unsigned char Rnum, unsigned char slave_add);

extern  void cmt_init(void);

#endif	/* I2CLIB_H */
