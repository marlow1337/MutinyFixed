#pragma once

#include "misc.h"
#include "dataupdatetypes.h"

class IClientRenderable;
class CBaseEntity;
//-----------------------------------------------------------------------------
// Particle attachment methods
//-----------------------------------------------------------------------------
enum ParticleAttachment_t
{
	PATTACH_ABSORIGIN = 0,			// Create at absorigin, but don't follow
	PATTACH_ABSORIGIN_FOLLOW,		// Create at absorigin, and update to follow the entity
	PATTACH_CUSTOMORIGIN,			// Create at a custom origin, but don't follow
	PATTACH_POINT,					// Create on attachment point, but don't follow
	PATTACH_POINT_FOLLOW,			// Create on attachment point, and update to follow the entity

	PATTACH_WORLDORIGIN,			// Used for control points that don't attach to an entity

	PATTACH_ROOTBONE_FOLLOW,		// Create at the root bone of the entity, and update to follow

	MAX_PATTACH_TYPES,
};

struct te_tf_particle_effects_colors_t
{
	Vector m_vecColor1;
	Vector m_vecColor2;
};

struct te_tf_particle_effects_control_point_t
{
	ParticleAttachment_t m_eParticleAttachment;
	Vector m_vecOffset;
};

// This is the class that holds whatever data we're sending down to the client to make the effect.
class CEffectData
{
public:
	Vector m_vOrigin;
	Vector m_vStart;
	Vector m_vNormal;
	QAngle m_vAngles;
	int		flags;
	int /*ClientEntityHandle_t*/ m_hEntity;
	float	m_flScale;
	float	m_flMagnitude;
	float	m_flRadius;
	int		m_nAttachmentIndex;
	short	m_nSurfaceProp;

	// Some TF2 specific things
	int		m_nMaterial;
	int		m_nDamageType;
	int		m_nHitBox;

	int		m_nOtherEntIndex;

	unsigned char	m_nColor;

	// Don't mess with stuff below here. DispatchEffect handles all of this.
public:
	CEffectData()
	{
		m_vOrigin.Init();
		m_vStart.Init();
		m_vNormal.Init();
		m_vAngles.Init();

		flags = 0;
		m_hEntity = -1;
		m_flScale = 1.f;
		m_nAttachmentIndex = 0;
		m_nSurfaceProp = 0;

		m_flMagnitude = 0.0f;
		m_flRadius = 0.0f;

		m_nMaterial = 0;
		m_nDamageType = 0;
		m_nHitBox = 0;

		m_nColor = 0;

		m_nOtherEntIndex = 0;
	}

	int GetEffectNameIndex() { return m_iEffectName; }

	IClientRenderable *GetRenderable() const;
	CBaseEntity *GetEntity() const;
	int entindex() const;

//private:

	int m_iEffectName;	// Entry in the EffectDispatch network string table. The is automatically handled by DispatchEffect().
};

class C_TEEffectDispatch
{
public:
	char pad[12];
	CEffectData m_EffectData;
	//C_TE_BloodStream
	// particle effect sort origin
	//char pad[9];
	//char			r, g, b, a;
	//char pad[12];
	//Vector origin; //12
	
	//char			m_nAmount;
	//char pad[4];
	//Vector m_vecOrigin;
	//Vector m_vecDirection;
};