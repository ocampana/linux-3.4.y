#include "higmac.h"
#include "phy_fix.h"

static const u32 phy_fix_param[] = {
	0x33f9, 0xbd,
	0x33fa, 0x34,
	0x33fb, 0x00,
	0x33fc, 0x39,
	0x3400, 0x39,
	0x3401, 0xCC,
	0x3402, 0x10,
	0x3403, 0x03,
	0x3404, 0xFD,
	0x3405, 0xFF,
	0x3406, 0xF0,
	0x3407, 0xF6,
	0x3408, 0x35,
	0x3409, 0xF4,
	0x340A, 0x26,
	0x340B, 0x37,
	0x340C, 0xC6,
	0x340D, 0x01,
	0x340E, 0xF7,
	0x340F, 0x35,
	0x3410, 0xF4,
	0x3411, 0xC6,
	0x3412, 0xB0,
	0x3413, 0xF7,
	0x3414, 0x01,
	0x3415, 0xFE,
	0x3416, 0xC6,
	0x3417, 0x0F,
	0x3418, 0xF7,
	0x3419, 0x01,
	0x341A, 0xFF,
	0x341B, 0xCC,
	0x341C, 0x34,
	0x341D, 0xC5,
	0x341E, 0xFD,
	0x341F, 0x00,
	0x3420, 0xD1,
	0x3421, 0xCC,
	0x3422, 0x35,
	0x3423, 0xA4,
	0x3424, 0xFD,
	0x3425, 0x00,
	0x3426, 0xD3,
	0x3427, 0xCC,
	0x3428, 0x34,
	0x3429, 0x56,
	0x342A, 0xFD,
	0x342B, 0x01,
	0x342C, 0xD6,
	0x342D, 0xF6,
	0x342E, 0x20,
	0x342F, 0xAA,
	0x3430, 0xCB,
	0x3431, 0x04,
	0x3432, 0xC4,
	0x3433, 0x1F,
	0x3434, 0xF7,
	0x3435, 0x35,
	0x3436, 0xF5,
	0x3437, 0xC1,
	0x3438, 0x0F,
	0x3439, 0x23,
	0x343A, 0x05,
	0x343B, 0xC6,
	0x343C, 0x0F,
	0x343D, 0xF7,
	0x343E, 0x35,
	0x343F, 0xF5,
	0x3440, 0xF7,
	0x3441, 0x20,
	0x3442, 0xAA,
	0x3443, 0x39,
	0x3444, 0x18,
	0x3445, 0xCE,
	0x3446, 0x35,
	0x3447, 0xED,
	0x3448, 0x18,
	0x3449, 0x3A,
	0x344A, 0xF6,
	0x344B, 0x20,
	0x344C, 0x09,
	0x344D, 0xC4,
	0x344E, 0xF0,
	0x344F, 0x18,
	0x3450, 0xEA,
	0x3451, 0x00,
	0x3452, 0xF7,
	0x3453, 0x20,
	0x3454, 0x09,
	0x3455, 0x39,
	0x3456, 0xF6,
	0x3457, 0x01,
	0x3458, 0xEC,
	0x3459, 0x27,
	0x345A, 0x68,
	0x345B, 0xF6,
	0x345C, 0x20,
	0x345D, 0x09,
	0x345E, 0xC4,
	0x345F, 0x0F,
	0x3460, 0xF7,
	0x3461, 0x01,
	0x3462, 0xE4,
	0x3463, 0xF6,
	0x3464, 0x1C,
	0x3465, 0xC2,
	0x3466, 0xC1,
	0x3467, 0x7F,
	0x3468, 0x23,
	0x3469, 0x0B,
	0x346A, 0xF6,
	0x346B, 0x1C,
	0x346C, 0xC2,
	0x346D, 0xC1,
	0x346E, 0x90,
	0x346F, 0x24,
	0x3470, 0x04,
	0x3471, 0xC6,
	0x3472, 0x01,
	0x3473, 0x20,
	0x3474, 0x2D,
	0x3475, 0xF6,
	0x3476, 0x1C,
	0x3477, 0xC2,
	0x3478, 0xC1,
	0x3479, 0x90,
	0x347A, 0x25,
	0x347B, 0x0B,
	0x347C, 0xF6,
	0x347D, 0x1C,
	0x347E, 0xC2,
	0x347F, 0xC1,
	0x3480, 0xA0,
	0x3481, 0x24,
	0x3482, 0x04,
	0x3483, 0xC6,
	0x3484, 0x02,
	0x3485, 0x20,
	0x3486, 0x1B,
	0x3487, 0xF6,
	0x3488, 0x1C,
	0x3489, 0xC2,
	0x348A, 0xC1,
	0x348B, 0xA0,
	0x348C, 0x25,
	0x348D, 0x0B,
	0x348E, 0xF6,
	0x348F, 0x1C,
	0x3490, 0xC2,
	0x3491, 0xC1,
	0x3492, 0xD0,
	0x3493, 0x24,
	0x3494, 0x04,
	0x3495, 0xC6,
	0x3496, 0x03,
	0x3497, 0x20,
	0x3498, 0x09,
	0x3499, 0xF6,
	0x349A, 0x1C,
	0x349B, 0xC2,
	0x349C, 0xC1,
	0x349D, 0xD0,
	0x349E, 0x25,
	0x349F, 0x04,
	0x34A0, 0xC6,
	0x34A1, 0x04,
	0x34A2, 0x8D,
	0x34A3, 0xA0,
	0x34A4, 0xF6,
	0x34A5, 0x20,
	0x34A6, 0x09,
	0x34A7, 0xC4,
	0x34A8, 0x0F,
	0x34A9, 0xF7,
	0x34AA, 0x01,
	0x34AB, 0xEB,
	0x34AC, 0x7A,
	0x34AD, 0x01,
	0x34AE, 0xEC,
	0x34AF, 0xF6,
	0x34B0, 0x01,
	0x34B1, 0xE4,
	0x34B2, 0xF1,
	0x34B3, 0x01,
	0x34B4, 0xEB,
	0x34B5, 0x27,
	0x34B6, 0x0C,
	0x34B7, 0xC6,
	0x34B8, 0x01,
	0x34B9, 0x37,
	0x34BA, 0xC6,
	0x34BB, 0x51,
	0x34BC, 0xBD,
	0x34BD, 0xD3,
	0x34BE, 0xDF,
	0x34BF, 0x31,
	0x34C0, 0xC6,
	0x34C1, 0x01,
	0x34C2, 0x39,
	0x34C3, 0x5F,
	0x34C4, 0x39,
	0x34C5, 0xF6,
	0x34C6, 0x01,
	0x34C7, 0xC0,
	0x34C8, 0xC1,
	0x34C9, 0x13,
	0x34CA, 0x25,
	0x34CB, 0x03,
	0x34CC, 0x7E,
	0x34CD, 0x35,
	0x34CE, 0x6E,
	0x34CF, 0xBD,
	0x34D0, 0xEE,
	0x34D1, 0x8F,
	0x34D2, 0x34,
	0x34D3, 0xF9,
	0x34D4, 0x34,
	0x34D5, 0xFC,
	0x34D6, 0x35,
	0x34D7, 0x0B,
	0x34D8, 0x35,
	0x34D9, 0x0F,
	0x34DA, 0x35,
	0x34DB, 0x13,
	0x34DC, 0x35,
	0x34DD, 0x1F,
	0x34DE, 0x35,
	0x34DF, 0x23,
	0x34E0, 0x35,
	0x34E1, 0x30,
	0x34E2, 0x35,
	0x34E3, 0x34,
	0x34E4, 0x35,
	0x34E5, 0x38,
	0x34E6, 0x35,
	0x34E7, 0x3C,
	0x34E8, 0x35,
	0x34E9, 0x3F,
	0x34EA, 0x35,
	0x34EB, 0x43,
	0x34EC, 0x35,
	0x34ED, 0x47,
	0x34EE, 0x35,
	0x34EF, 0x5C,
	0x34F0, 0x35,
	0x34F1, 0x60,
	0x34F2, 0x35,
	0x34F3, 0x64,
	0x34F4, 0x35,
	0x34F5, 0x68,
	0x34F6, 0x35,
	0x34F7, 0x6B,
	0x34F8, 0x39,
	0x34F9, 0xBD,
	0x34FA, 0xBC,
	0x34FB, 0x25,
	0x34FC, 0xBD,
	0x34FD, 0xBC,
	0x34FE, 0x33,
	0x34FF, 0xF6,
	0x3500, 0x01,
	0x3501, 0xFF,
	0x3502, 0xF7,
	0x3503, 0x20,
	0x3504, 0xA5,
	0x3505, 0xC6,
	0x3506, 0x08,
	0x3507, 0xF7,
	0x3508, 0x20,
	0x3509, 0xA8,
	0x350A, 0x39,
	0x350B, 0xBD,
	0x350C, 0xBC,
	0x350D, 0x71,
	0x350E, 0x39,
	0x350F, 0xBD,
	0x3510, 0xBC,
	0x3511, 0x94,
	0x3512, 0x39,
	0x3513, 0xBD,
	0x3514, 0xBD,
	0x3515, 0x07,
	0x3516, 0xC6,
	0x3517, 0x02,
	0x3518, 0x37,
	0x3519, 0xC6,
	0x351A, 0x51,
	0x351B, 0xBD,
	0x351C, 0xD3,
	0x351D, 0xDF,
	0x351E, 0x31,
	0x351F, 0xBD,
	0x3520, 0xBD,
	0x3521, 0x38,
	0x3522, 0x39,
	0x3523, 0xBD,
	0x3524, 0xBD,
	0x3525, 0x90,
	0x3526, 0xC6,
	0x3527, 0x02,
	0x3528, 0x37,
	0x3529, 0xC6,
	0x352A, 0x51,
	0x352B, 0xBD,
	0x352C, 0xD3,
	0x352D, 0xDF,
	0x352E, 0x31,
	0x352F, 0x39,
	0x3530, 0xBD,
	0x3531, 0xBD,
	0x3532, 0xC0,
	0x3533, 0x39,
	0x3534, 0xBD,
	0x3535, 0xBE,
	0x3536, 0x07,
	0x3537, 0x39,
	0x3538, 0xBD,
	0x3539, 0xBE,
	0x353A, 0x6A,
	0x353B, 0x39,
	0x353C, 0xBD,
	0x353D, 0xBE,
	0x353E, 0xB0,
	0x353F, 0xBD,
	0x3540, 0xBF,
	0x3541, 0x05,
	0x3542, 0x39,
	0x3543, 0xBD,
	0x3544, 0xC0,
	0x3545, 0x60,
	0x3546, 0x39,
	0x3547, 0xBD,
	0x3548, 0xC0,
	0x3549, 0x7E,
	0x354A, 0xF6,
	0x354B, 0x01,
	0x354C, 0xFE,
	0x354D, 0xF7,
	0x354E, 0x1C,
	0x354F, 0xC0,
	0x3550, 0xBD,
	0x3551, 0x9A,
	0x3552, 0xD9,
	0x3553, 0xC6,
	0x3554, 0x02,
	0x3555, 0x37,
	0x3556, 0xC6,
	0x3557, 0x51,
	0x3558, 0xBD,
	0x3559, 0xD3,
	0x355A, 0xDF,
	0x355B, 0x31,
	0x355C, 0xBD,
	0x355D, 0xC0,
	0x355E, 0xB2,
	0x355F, 0x39,
	0x3560, 0xBD,
	0x3561, 0xC0,
	0x3562, 0xDD,
	0x3563, 0x39,
	0x3564, 0xBD,
	0x3565, 0xC1,
	0x3566, 0x7E,
	0x3567, 0x39,
	0x3568, 0xBD,
	0x3569, 0xC1,
	0x356A, 0x9F,
	0x356B, 0xBD,
	0x356C, 0xC1,
	0x356D, 0xBF,
	0x356E, 0x39,
	0x356F, 0x3C,
	0x3570, 0xF6,
	0x3571, 0x00,
	0x3572, 0x46,
	0x3573, 0x4F,
	0x3574, 0xC4,
	0x3575, 0x03,
	0x3576, 0x83,
	0x3577, 0x00,
	0x3578, 0x02,
	0x3579, 0x27,
	0x357A, 0x02,
	0x357B, 0x38,
	0x357C, 0x39,
	0x357D, 0xF6,
	0x357E, 0x00,
	0x357F, 0x47,
	0x3580, 0xC4,
	0x3581, 0xFC,
	0x3582, 0xCA,
	0x3583, 0x02,
	0x3584, 0xF7,
	0x3585, 0x00,
	0x3586, 0x47,
	0x3587, 0xFE,
	0x3588, 0x00,
	0x3589, 0xB5,
	0x358A, 0xAD,
	0x358B, 0x00,
	0x358C, 0x13,
	0x358D, 0x00,
	0x358E, 0x10,
	0x358F, 0x03,
	0x3590, 0x7F,
	0x3591, 0x12,
	0x3592, 0x37,
	0x3593, 0xF6,
	0x3594, 0x01,
	0x3595, 0xEE,
	0x3596, 0xF7,
	0x3597, 0x12,
	0x3598, 0x36,
	0x3599, 0xC6,
	0x359A, 0x01,
	0x359B, 0xF7,
	0x359C, 0x12,
	0x359D, 0x51,
	0x359E, 0x5C,
	0x359F, 0xF7,
	0x35A0, 0x01,
	0x35A1, 0xBF,
	0x35A2, 0x38,
	0x35A3, 0x39,
	0x35A4, 0xF6,
	0x35A5, 0x01,
	0x35A6, 0xBF,
	0x35A7, 0xC1,
	0x35A8, 0x0B,
	0x35A9, 0x24,
	0x35AA, 0x41,
	0x35AB, 0xBD,
	0x35AC, 0xEE,
	0x35AD, 0x8F,
	0x35AE, 0x35,
	0x35AF, 0xC5,
	0x35B0, 0x35,
	0x35B1, 0xC8,
	0x35B2, 0x35,
	0x35B3, 0xCB,
	0x35B4, 0x35,
	0x35B5, 0xCE,
	0x35B6, 0x35,
	0x35B7, 0xD6,
	0x35B8, 0x35,
	0x35B9, 0xDA,
	0x35BA, 0x35,
	0x35BB, 0xDE,
	0x35BC, 0x35,
	0x35BD, 0xE9,
	0x35BE, 0x35,
	0x35BF, 0xD2,
	0x35C0, 0x35,
	0x35C1, 0xE2,
	0x35C2, 0x35,
	0x35C3, 0xE6,
	0x35C4, 0x39,
	0x35C5, 0xBD,
	0x35C6, 0xC2,
	0x35C7, 0x47,
	0x35C8, 0x8D,
	0x35C9, 0xA5,
	0x35CA, 0x39,
	0x35CB, 0xBD,
	0x35CC, 0xC2,
	0x35CD, 0x86,
	0x35CE, 0xBD,
	0x35CF, 0xC2,
	0x35D0, 0xC0,
	0x35D1, 0x39,
	0x35D2, 0xBD,
	0x35D3, 0xC3,
	0x35D4, 0x40,
	0x35D5, 0x39,
	0x35D6, 0xBD,
	0x35D7, 0xC4,
	0x35D8, 0x07,
	0x35D9, 0x39,
	0x35DA, 0xBD,
	0x35DB, 0xC4,
	0x35DC, 0x45,
	0x35DD, 0x39,
	0x35DE, 0xBD,
	0x35DF, 0xC4,
	0x35E0, 0x98,
	0x35E1, 0x39,
	0x35E2, 0xBD,
	0x35E3, 0xC4,
	0x35E4, 0xF3,
	0x35E5, 0x39,
	0x35E6, 0xBD,
	0x35E7, 0xC5,
	0x35E8, 0x14,
	0x35E9, 0xBD,
	0x35EA, 0xC5,
	0x35EB, 0x2E,
	0x35EC, 0x39,
	0x35ED, 0x00,
	0x35EE, 0x04,
	0x35EF, 0x08,
	0x35F0, 0x09,
	0x35F1, 0x0D,
	0x35F2, 0x0E,
	0x35F3, 0x0F,
	0x35F4, 0x00,
	0x3400, 0x01,
	0x33f8, 0x01
};

int set_phy_expanded_access_mode(struct phy_device *phy_dev, int access_mode)
{
	int v, ret;

	v = phy_read(phy_dev, MII_MISC_CTL);
	v &= (~0x3);
	v |= (access_mode & 0x3);
	ret = phy_write(phy_dev, MII_MISC_CTL, v);

	return ret;
}

int phy_expanded_read(struct phy_device *phy_dev, u32 reg_addr)
{
	int v, ret;

	v = phy_read(phy_dev, MII_BMCR);
	v |= BMCR_PDOWN;
	phy_write(phy_dev, MII_BMCR, v);

	phy_write(phy_dev, MII_EXPMA, reg_addr);
	ret = phy_read(phy_dev, MII_EXPMD);

	v = phy_read(phy_dev, MII_BMCR);
	v &= (~BMCR_PDOWN);
	phy_write(phy_dev, MII_BMCR, v);

	return ret;
}

int phy_expanded_write(struct phy_device *phy_dev, u32 reg_addr, u16 val)
{
	int v, ret;

	v = phy_read(phy_dev, MII_BMCR);
	v |= BMCR_PDOWN;
	phy_write(phy_dev, MII_BMCR, v);

	phy_write(phy_dev, MII_EXPMA, reg_addr);
	ret = phy_write(phy_dev, MII_EXPMD, val);

	v = phy_read(phy_dev, MII_BMCR);
	v &= (~BMCR_PDOWN);
	phy_write(phy_dev, MII_BMCR, v);

	return ret;
}

int phy_expanded_write_bulk(struct phy_device *phy_dev, const u32 reg_and_val[],
			    int count)
{
	int i, v, ret = 0;
	u32 reg_addr;
	u16 val;

	v = phy_read(phy_dev, MII_BMCR);
	v |= BMCR_PDOWN;
	phy_write(phy_dev, MII_BMCR, v);

	for (i = 0; i < (2 * count); i += 2) {
		reg_addr = reg_and_val[i];
		val = (u16) reg_and_val[i + 1];
		phy_write(phy_dev, MII_EXPMA, reg_addr);
		ret = phy_write(phy_dev, MII_EXPMD, val);
	}

	v = phy_read(phy_dev, MII_BMCR);
	v &= (~BMCR_PDOWN);
	phy_write(phy_dev, MII_BMCR, v);

	return ret;
}

/* fix FEPHY for better eye diagram */
int hisilicon_fephy_fix(struct phy_device *phy_dev)
{
	int count;

	count = sizeof(phy_fix_param) / sizeof(phy_fix_param[0]);
	if (count % 2)
		pr_warn("internal FEPHY fix register count is not right.\n");
	count /= 2;

	phy_expanded_write_bulk(phy_dev, phy_fix_param, count);

	return 0;
}

/*
 * for a better Electromagnetic Compatibility
 */
int realtek_gephy_fix(struct phy_device *phy_dev)
{
#if 0
	int v;

	pr_info("RealTek phy fix: phy id=0x%x\n", phy_dev->phy_id);

	v = phy_read(phy_dev, 16);      /* PHYCR reg */
	v |= 1 << 4;                    /* clk125 remains at logic low */
	phy_write(phy_dev, 16, v);

	phy_write(phy_dev, 31, 0x0007);	/* set to extension page */
	phy_write(phy_dev, 30, 0x00A0);	/* set to extension page 160 */

	v = phy_read(phy_dev, 26);
	v &= ~(1 << 2);			/* enable RXC SSC */
	phy_write(phy_dev, 26, v);

	phy_write(phy_dev, 31, 0x0);	/* back to page 0 */

#endif

	return 0;
}

/* copy from phy_quirk() in hieth-sf/net.c */
int KSZ8051MNL_phy_fix(struct phy_device *phy_dev)
{
	u32 v;

	v = phy_read(phy_dev, 0x1F);
	v |= (1 << 7);       /* set phy RMII 50MHz clk; */
	phy_write(phy_dev, 0x1F, v);

	v = phy_read(phy_dev, 0x16);
	v |= (1 << 1);       /* set phy RMII override; */
	phy_write(phy_dev, 0x16, v);

	return 0;
}

/* copy from phy_quirk() in hieth-sf/net.c */
int KSZ8081RNB_phy_fix(struct phy_device *phy_dev)
{
	u32 v;

	v = phy_read(phy_dev, 0x1F);
	v |= (1 << 7);       /* set phy RMII 50MHz clk; */
	phy_write(phy_dev, 0x1F, v);

	return 0;
}

void phy_register_fixups(void)
{
	phy_register_fixup_for_uid(REALTEK_PHY_ID_8211EG,
			REALTEK_PHY_MASK, realtek_gephy_fix);
	phy_register_fixup_for_uid(HISILICON_PHY_ID_FESTAV200,
			HISILICON_PHY_MASK, hisilicon_fephy_fix);
	phy_register_fixup_for_uid(PHY_ID_KSZ8051MNL,
			DEFAULT_PHY_MASK, KSZ8051MNL_phy_fix);
	phy_register_fixup_for_uid(PHY_ID_KSZ8081RNB,
			DEFAULT_PHY_MASK, KSZ8081RNB_phy_fix);
}
