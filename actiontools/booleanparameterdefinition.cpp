/*
	Actiona
	Copyright (C) 2008-2015 Jonathan Mercier-Ganady

	Actiona is free software: you can redistribute it and/or modify
	it under the terms of the GNU General Public License as published by
	the Free Software Foundation, either version 3 of the License, or
	(at your option) any later version.

	Actiona is distributed in the hope that it will be useful,
	but WITHOUT ANY WARRANTY; without even the implied warranty of
	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
	GNU General Public License for more details.

	You should have received a copy of the GNU General Public License
	along with this program. If not, see <http://www.gnu.org/licenses/>.

	Contact : jmgr@jmgr.info
*/

#include "booleanparameterdefinition.h"
#include "booleanedit.h"
#include "actioninstance.h"

namespace ActionTools
{
    BooleanParameterDefinition::BooleanParameterDefinition(const Name &name, QObject *parent)
        : ParameterDefinition(name, parent),
		mBooleanEdit(0)
	{
	}

	void BooleanParameterDefinition::buildEditors(Script *script, QWidget *parent)
	{
		ParameterDefinition::buildEditors(script, parent);

		mBooleanEdit = new BooleanEdit(parent);

		addEditor(mBooleanEdit);
	}

	void BooleanParameterDefinition::load(const ActionInstance *actionInstance)
	{
		mBooleanEdit->setFromSubParameter(actionInstance->subParameter(name().original(), "value"));
	}

	void BooleanParameterDefinition::save(ActionInstance *actionInstance)
	{
		actionInstance->setSubParameter(name().original(), "value", mBooleanEdit->isCode(), mBooleanEdit->text());
	}
}

