#pragma once

#include <QtCore>

#include "Markup/Highlight.hpp"
#include "Strings.hpp"
#include "Vector.hpp"

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
	Node(Type type, QString &&value) : type{type}, value{std::move(value)} {}
	Node(Node &&) = default;
	Node & operator = (Node &&) = default;

	static Type typeFromName(const QString &name);
	QString toString() const;

	Node & appendNode(Node::Type type, const QString &value);
	Node & appendNode(Node::Type type, QString &&value);

	Type type;
	QString value;
	bool endParagraph = false;
	Vector <Node> children;
};
