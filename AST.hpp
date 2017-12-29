#pragma once

#include <QtCore>

#include "Markup/Highlight.hpp"
#include "Strings.hpp"

extern const QSet <QString> Environment;
extern const QSet <QString> Fragment;
extern const QSet <QString> Tag;

struct Node {
	enum class Type : quint8 {
		Invalid,
		Environment,
		Fragment,
		Tag,
		Text,
	};

	Node() = default;
	Node(Type type, const QString &value) : type{type}, value{value} {}

	static Type typeFromName(const QString &name);
	QString toString() const;

	Type type;
	QString value;
	bool endParagraph = false;
	QVector <Node *> children;
};