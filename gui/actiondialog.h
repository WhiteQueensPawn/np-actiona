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

#ifndef ACTIONDIALOG_H
#define ACTIONDIALOG_H

#include "parametercontainer.h"

#include <QDialog>
#include <QVector>
#include <QList>
#include <QSet>

namespace Ui
{
	class ActionDialog;
}

namespace ActionTools
{
	class ActionDefinition;
	class ActionInstance;
	class GroupDefinition;
	class ParameterDefinition;
	class Script;
}

class QAbstractItemModel;
class QFormLayout;
class QGridLayout;
class QTabWidget;
class QSpinBox;

class ActionDialog : public QDialog, public ActionTools::ParameterContainer
{
	Q_OBJECT

public:
	ActionDialog(QAbstractItemModel *completionModel, ActionTools::Script *script, ActionTools::ActionDefinition *actionDefinition, const QString &localeName, QWidget *parent = 0);
	~ActionDialog();

    virtual QMenu *createVariablesMenu(QWidget *parent) const;

    using QDialog::exec;
public slots:
	void accept();
	int exec(ActionTools::ActionInstance *actionInstance, const QString &field, const QString &subField, int currentLine, int currentColumn);
	int exec(ActionTools::ActionInstance *actionInstance, int exception);
	
private slots:
	void postInit();
	void currentExceptionActionChanged(int index);

private:
	enum
	{
		InputParameters,
		OutputParameters
	};

	void addParameter(ActionTools::ParameterDefinition *parameter, int tab);

	Ui::ActionDialog *ui;
	ActionTools::ActionInstance *mActionInstance;
	ActionTools::Script *mScript;
	QList<ActionTools::ParameterDefinition *> mParameters;
	QString mCurrentField;
	QString mCurrentSubField;
	int mCurrentLine;
	int mCurrentColumn;
	int mCurrentException;
	QAbstractItemModel *mCompletionModel;
	QVector<QFormLayout *> mParameterLayouts[2];
	QGridLayout *mExceptionsLayout;
	QTabWidget *mTabWidget;
	QWidget *mExceptionsTabWidget;
	QWidget *mCommonTabWidget;
	QList<QWidget *> mParameterTabWidgets;
	QSpinBox *mPauseBeforeSpinBox;
	QSpinBox *mPauseAfterSpinBox;
	QSpinBox *mTimeoutSpinBox;
    QSet<QString> mOtherActionsVariables;

	Q_DISABLE_COPY(ActionDialog)
};

#endif // ACTIONDIALOG_H
