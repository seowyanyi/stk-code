#ifndef STK_TEXT_BILLBOARD_HPP
#define STK_TEXT_BILLBOARD_HPP

#include "../lib/irrlicht/source/Irrlicht/CBillboardSceneNode.h"
#include <IBillboardSceneNode.h>
#include <irrTypes.h>
#include <IMesh.h>
#include "graphics/stkmeshscenenode.hpp"
#include "guiengine/scalable_font.hpp"
#include "utils/cpp2011.hpp"

class STKTextBillboardChar
{
public:
    irr::video::ITexture* m_texture;
    irr::core::rect<irr::s32> m_destRect;
    irr::core::rect<irr::s32> m_sourceRect;
    irr::video::SColor m_colors[4];

    STKTextBillboardChar(irr::video::ITexture* texture,
        const irr::core::rect<irr::s32>& destRect,
        const irr::core::rect<irr::s32>& sourceRect,
        const irr::video::SColor* const colors)
    {
        m_texture = texture;
        m_destRect = destRect;
        m_sourceRect = sourceRect;
        if (colors == NULL)
        {
            m_colors[0] = m_colors[1] = m_colors[2] = m_colors[3] = NULL;
        }
        else
        {
            m_colors[0] = colors[0];
            m_colors[1] = colors[1];
            m_colors[2] = colors[2];
            m_colors[3] = colors[3];
        }
    }
};

class STKTextBillboard : public STKMeshSceneNode, irr::gui::FontCharCollector
{
    std::vector<STKTextBillboardChar> m_chars;

    irr::scene::IMesh* getTextMesh(irr::core::stringw text, gui::ScalableFont* font,
        const irr::video::SColor& color);

public:
    STKTextBillboard(irr::core::stringw text, irr::gui::ScalableFont* font,
        const irr::video::SColor& color, irr::scene::ISceneNode* parent,
        irr::scene::ISceneManager* mgr, irr::s32 id,
        const irr::core::vector3df& position,
        const irr::core::vector3df& size);

    virtual void OnRegisterSceneNode() OVERRIDE;

    virtual void collectChar(irr::video::ITexture* texture,
        const irr::core::rect<irr::s32>& destRect,
        const irr::core::rect<irr::s32>& sourceRect,
        const irr::video::SColor* const colors);
};

#endif